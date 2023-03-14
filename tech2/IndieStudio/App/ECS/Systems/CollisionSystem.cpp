/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** CollisionSystem
*/

#include "CollisionSystem.hpp"


void ecs::CollisionSystem::update(float dt) const {
    (void)dt;
    std::vector<Entity> toRemove;
    for (ecs::Entity const &e1 : entities) {
        RigidBody &rigidBody = ecs::Coordinator::getInstance().getComponent<RigidBody>(e1);
        Transform3D &t1 = ecs::Coordinator::getInstance().getComponent<Transform3D>(e1);

        if (rigidBody.type == SPREAD) {
            this->hitSpread(e1, t1, rigidBody);
            continue;
        }

        if (!rigidBody.movable) continue;

        rigidBody.grounded = false;

        for (ecs::Entity const &e2 : entities) {
            if (e1 == e2) continue;

            Transform3D &t2 = ecs::Coordinator::getInstance().getComponent<Transform3D>(e2);
            RigidBody &b2 = ecs::Coordinator::getInstance().getComponent<RigidBody>(e2);

            rl::BoundingBox bb1(
                t1.position - t1.scale / 2.0f,
                t1.position + t1.scale / 2.0f
            );
            rl::BoundingBox const bb2(
                t2.position - t2.scale / 2.0f,
                t2.position + t2.scale / 2.0f
            );
            if (b2.type == SPREAD || !bb1.checkCollisionBoxes(bb2)) continue;
            // TODO: check for quadrant
            if (b2.type >= rigidBody.type) {
                this->getBlocked(t1, t2, rigidBody, dt);
                if (rigidBody.type == HIT && b2.type != HIT) {
                    if (b2.type == PLAYER) {
                        rl::SoundManager::getInstance().getData(rl::SOUND_PLAYER_DEATH).play();
                    }
                    this->hitDetection(e1, e2, b2.type);
                    continue;
                }
            }
            if (b2.type == ITEM) {
                if (rigidBody.type == PLAYER || rigidBody.type == PASS_BOMB || rigidBody.type == GHOST) {
                    Item &it = ecs::Coordinator::getInstance().getComponent<Item>(e2);
                    it.entity = e1;
                    it.taken = true;
                } else if (rigidBody.type == BOMB) {
                    this->getBlocked(t1, t2, rigidBody, dt);
                    toRemove.push_back(e2);
                }
                // else {
                //     //TODO: alive.dead = true;
                // }
            }
        }
    }

    for (ecs::Entity entity : toRemove) {
        ecs::Coordinator::getInstance().destroyEntity(entity);
    }
}

void ecs::CollisionSystem::hitDetection(Entity const &e1, Entity const &e2, CollisionType type) const
{
    // std::cout << "TYpe = [" << type << "]" << std::endl;
    if (type == SOLID || type == HIT) return;

    Alive &alive = ecs::Coordinator::getInstance().getComponent<Alive>(e2);
    Damage &dmg  = ecs::Coordinator::getInstance().getComponent<Damage>(e1);

    alive.health -= (dmg.damage - alive.armor);

}


void ecs::CollisionSystem::getBlocked(Transform3D &t1, Transform3D &t2, RigidBody &body, float dt) const
{

    rl::BoundingBox bb1(
        t1.position - t1.scale / 2.0f,
        t1.position + t1.scale / 2.0f
    );
    rl::BoundingBox const bb2(
        t2.position - t2.scale / 2.0f,
        t2.position + t2.scale / 2.0f
    );

    rl::BoundingBox bbPast = bb1;
    bbPast.max.x   += body.velocity.x * -dt;
    bbPast.max.y   += body.velocity.y * -dt;
    bbPast.max.z   += body.velocity.z * -dt;

    bbPast.min.x   += body.velocity.x * -dt;
    bbPast.min.y   += body.velocity.y * -dt;
    bbPast.min.z   += body.velocity.z * -dt;

    bool x = false;
    bool z = false;

    if (bb2.checkCollisionBoxes(bbPast) && body.type != HIT) return;
    if (body.type == HIT) return;
    // {
    //     // return this->hitSpread();
    //     std::cout << "HIT collides" << std::endl;
    //     return;
    // }
    rl::Vector3 direction = std::move(body.velocity.direction());

    rl::BoundingBox bbSide = bbPast;
    bbSide.min.z   += body.velocity.z * dt;
    bbSide.max.z   += body.velocity.z * dt;
    if (bb2.checkCollisionBoxes(bbSide)) {
        t1.position.z += ((t1.scale.z + t2.scale.z  + 0.001) / 2 - fabs(t2.position.z - t1.position.z) ) * -direction.z;
        body.velocity.z = 0;
        body.acceleration.z = 0;
        z = true;
    }

    rl::BoundingBox bbFront = bbPast;
    bbFront.min.x  += body.velocity.x * dt;
    bbFront.max.x  += body.velocity.x * dt;
    if (bb2.checkCollisionBoxes(bbFront)) {
        // t1.position.x += body.velocity.x * -dt;
        t1.position.x += ((t1.scale.x + t2.scale.x + 0.001) / 2 - fabs(t2.position.x - t1.position.x) ) * -direction.x;
        body.velocity.x = 0;
        body.acceleration.x = 0;
        x = true;
    }

    if (!x && !z) {
        bbFront.min.z = bbSide.min.z;
        bbFront.max.z = bbSide.max.z;
        if (bb2.checkCollisionBoxes(bbFront)) {
            t1.position.z += ((t1.scale.z + t2.scale.z  + 0.001) / 2 - fabs(t2.position.z - t1.position.z) ) * -direction.z;
            body.velocity.z = 0;
            body.acceleration.z = 0;
            t1.position.x += ((t1.scale.x + t2.scale.x + 0.001) / 2 - fabs(t2.position.x - t1.position.x) ) * -direction.x;
            body.velocity.x = 0;
            body.acceleration.x = 0;
        }
    }

    rl::BoundingBox bbHeight = bbPast;
    bbHeight.min.y += body.velocity.y * dt;
    bbHeight.max.y += body.velocity.y * dt;
    if (bb2.checkCollisionBoxes(bbHeight)) {
        t1.position.y += ((t1.scale.y + t2.scale.y + 0.001) / 2 - fabs(t2.position.y - t1.position.y) ) * -direction.y;
        if (body.velocity.y < 0) {
            body.acceleration.y = 0;
            body.grounded = true;
        }
        body.velocity.y = 0;
    }
}


void ecs::CollisionSystem::hitSpread(Entity const &e1, Transform3D &t1, RigidBody &body) const
{
    (void)body;
    // std::cout << "\n-------SPREADING-----" << std::endl;
    Spread &spread = ecs::Coordinator::getInstance().getComponent<Spread>(e1);


    rl::BoundingBox bb1 (
        (t1.position - t1.scale * 0.95/ 2.0f),
        (t1.position + t1.scale * 0.95/ 2.0f)
    );
    bb1.min.y += 0.3;
    bb1.max.y += 0.3;

    // std::cout << "BASE: \n\tmin [" << bb1.min.x << ", " << bb1.min.y << ", " << bb1.min.z << "]" << std::endl;
    // std::cout << "\tmax [" << bb1.max.x << ", " << bb1.max.y << ", " << bb1.max.z << "]" << std::endl;

    std::vector<rl::BoundingBox> boxesXPos;
    std::vector<rl::BoundingBox> boxesXNeg;
    std::vector<rl::BoundingBox> boxesZPos;
    std::vector<rl::BoundingBox> boxesZNeg;

    for (int i = 1; i <= spread.fire; ++i) {
        // std::cout << "*****TMP!!*****" <<std::endl;
        rl::BoundingBox tmp = bb1;
        tmp.min.x += i;
        tmp.max.x += i;
        boxesXPos.push_back(tmp);
        // std::cout << "XPOS: \n\tmin [" << tmp.min.x << ", " << tmp.min.y << ", " << tmp.min.z << "]" << std::endl;
        // std::cout << "\tmax [" << tmp.max.x << ", " << tmp.max.y << ", " << tmp.max.z << "]" << std::endl;
        tmp = bb1;
        tmp.min.x -= i;
        tmp.max.x -= i;
        boxesXNeg.push_back(tmp);
        // std::cout << "XNEG: \n\tmin [" << tmp.min.x << ", " << tmp.min.y << ", " << tmp.min.z << "]" << std::endl;
        // std::cout << "\tmax [" << tmp.max.x << ", " << tmp.max.y << ", " << tmp.max.z << "]" << std::endl;
        tmp = bb1;
        tmp.min.z += i;
        tmp.max.z += i;
        boxesZPos.push_back(tmp);
        // std::cout << "ZPOS: \n\tmin [" << tmp.min.x << ", " << tmp.min.y << ", " << tmp.min.z << "]" << std::endl;
        // std::cout << "\tmax [" << tmp.max.x << ", " << tmp.max.y << ", " << tmp.max.z << "]" << std::endl;
        tmp = bb1;
        tmp.min.z -= i;
        tmp.max.z -= i;
        boxesZNeg.push_back(tmp);
        // std::cout << "ZNEG: \n\tmin [" << tmp.min.x << ", " << tmp.min.y << ", " << tmp.min.z << "]" << std::endl;
        // std::cout << "\tmax [" << tmp.max.x << ", " << tmp.max.y << ", " << tmp.max.z << "]" << std::endl;
    }


    // for (auto tmp : boxesXPos) {
        // std::cout << "TEST XPOS: \n\tmin [" << tmp.min.x << ", " << tmp.min.y << ", " << tmp.min.z << "]" << std::endl;
        // std::cout << "\tmax [" << tmp.max.x << ", " << tmp.max.y << ", " << tmp.max.z << "]" << std::endl;
    // }
    // std::cout << "PRE" << std::endl;
    // std::cout << "size X+ = [" << boxesXPos.size() << "]" << std::endl;
    // std::cout << "size X- = [" << boxesXNeg.size() << "]" << std::endl;
    // std::cout << "size Z+ = [" << boxesZPos.size() << "]" << std::endl;
    // std::cout << "size Z- = [" << boxesZNeg.size() << "]" << std::endl;

    for (ecs::Entity const &e2 : entities) {
        if (e1 == e2) continue;

        Transform3D &t2 = ecs::Coordinator::getInstance().getComponent<Transform3D>(e2);
        RigidBody &b2 = ecs::Coordinator::getInstance().getComponent<RigidBody>(e2);

        if (b2.type == SPREAD || b2.type == PLAYER || b2.type == HIT || b2.type == BOMB) continue;

        rl::BoundingBox const bb2 (
            t2.position - t2.scale  * 0.95 / 2.0f,
            t2.position + t2.scale  * 0.95 / 2.0f
        );

        // std::cout << "+++" << std::endl;


        for (size_t i = 0; i < boxesXPos.size(); ++i) {
            if (bb2.checkCollisionBoxes(boxesXPos[i])) {
                // std::cout << "XPos COLLIDES with entity "<< e2 << ", of type " << b2.type << std::endl;
                if (b2.type == ITEM ||  b2.type == CRATE) {
                    boxesXPos.resize(i + 1);
                } else {
                    boxesXPos.resize(i);
                }
                break;
            }
        }
        for (size_t i = 0; i < boxesXNeg.size(); ++i) {
            if (bb2.checkCollisionBoxes(boxesXNeg[i])) {
                // std::cout << "XNeg COLLIDES with entity "<< e2 << ", of type " << b2.type << std::endl;
                if (b2.type == ITEM ||  b2.type == CRATE) {
                    boxesXNeg.resize(i + 1);
                } else {
                    boxesXNeg.resize(i);
                }

                break;
            }
        }

        for (size_t i = 0; i < boxesZPos.size(); ++i) {
            if (bb2.checkCollisionBoxes(boxesZPos[i])) {
                // std::cout << "ZPos COLLIDES with entity "<< e2 << ", of type " << b2.type << std::endl;
                if (b2.type == ITEM ||  b2.type == CRATE) {
                    boxesZPos.resize(i + 1);
                } else {
                    boxesZPos.resize(i);
                }
                break;
            }
        }
        for (size_t i = 0; i < boxesZNeg.size(); ++i) {
            if (bb2.checkCollisionBoxes(boxesZNeg[i])) {
                // std::cout << "ZNeg COLLIDES with entity "<< e2 << ", of type " << b2.type << std::endl;
                if (b2.type == ITEM ||  b2.type == CRATE) {
                    boxesZNeg.resize(i + 1);
                } else {
                    boxesZNeg.resize(i);
                }
                break;
            }
        }

        if (boxesXPos.size() + boxesXNeg.size() + boxesZPos.size() + boxesZNeg.size() == 0) {
            // std::cout << "ZERO" << std::endl;
            break;
        }
    }
    // std::cout << "POST" << std::endl;
    // std::cout << "size X+ = [" << boxesXPos.size() << "]" << std::endl;
    // std::cout << "size X- = [" << boxesXNeg.size() << "]" << std::endl;
    // std::cout << "size Z+ = [" << boxesZPos.size() << "]" << std::endl;
    // std::cout << "size Z- = [" << boxesZNeg.size() << "]" << std::endl;
    spread.sizeXPos = boxesXPos.size();
    spread.sizeZPos = boxesZPos.size();
    spread.sizeXNeg = boxesXNeg.size();
    spread.sizeZNeg = boxesZNeg.size();
    // std::cout << "size X = [" << spread.sizeX << "]" << std::endl;
    // std::cout << "size Z = [" << spread.sizeZ << "]" << std::endl;
    // rl::Vector3 posX(
    //     spread.posX.x - ((int)boxesXNeg.size() - (int)boxesXPos.size()) / 2,
    //     spread.posX.y,
    //     spread.posX.z
    // );
    // rl::Vector3 posZ(
    //     spread.posZ.x,
    //     spread.posZ.y,
    //     spread.posZ.z - ((int)boxesZNeg.size() - (int)boxesZPos.size()) / 2

    // );
    // std::cout << "POSZ: [" << posZ.x << ", " << posZ.y << ", " << posZ.z << "]" << std::endl;
    // std::cout << "PRE POSX: [" << spread.posX.x << ", " << spread.posX.y << ", " << spread.posX.z << "]" << std::endl;
    // std::cout << "PRE POSZ: [" << spread.posZ.x << ", " << spread.posZ.y << ", " << spread.posZ.z << "]" << std::endl;
    // std::cout << "Sizes: [" << (int)boxesXNeg.size() << ", " << (int)boxesXPos.size() << std::endl;
    // std::cout << "Sizes: [" << (int)boxesZNeg.size() << ", " << (int)boxesZPos.size() << std::endl;

    // spread.posX.x -= (float)((int)boxesXNeg.size() - (int)boxesXPos.size()) / 2;
    // spread.posZ.z -= (float)((int)boxesZNeg.size() - (int)boxesZPos.size()) / 2;

    // std::cout << "POST POSX: [" << spread.posX.x << ", " << spread.posX.y << ", " << spread.posX.z << "]" << std::endl;
    // std::cout << "POST POSZ: [" << spread.posZ.x << ", " << spread.posZ.y << ", " << spread.posZ.z << "]" << std::endl;
}



// std::cout << "------------------------------------------------------------------------------------------" << std::endl;

// std::cout << "Pre Player Speed : [" << rigidBody.velocity.x << ", " << rigidBody.velocity.y << ", " << rigidBody.velocity.z << "]" << std::endl;
// std::cout << "Pre Player Accel : [" << rigidBody.acceleration.x << ", " << rigidBody.acceleration.y << ", " << rigidBody.acceleration.z << "]" << std::endl;
// std::cout << "Pre Player Grounded? : ["  << rigidBody.grounded << "]" << std::endl << std::endl;

// std::cout << "Post Player Speed : [" << rigidBody.velocity.x << ", " << rigidBody.velocity.y << ", " << rigidBody.velocity.z << "]" << std::endl;
// std::cout << "Post Player Accel : [" << rigidBody.acceleration.x << ", " << rigidBody.acceleration.y << ", " << rigidBody.acceleration.z << "]" << std::endl;
