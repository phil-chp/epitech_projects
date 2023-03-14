/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Coordinator
*/

#include "Coordinator.hpp"

ecs::Coordinator::Coordinator()
    : _componentManager(std::make_shared<ComponentManager>())
    , _entityManager(std::make_shared<EntityManager>())
    , _systemManager(std::make_shared<SystemManager>())
{
    Signature signature;

    this->_systems.insert(std::make_pair(DRAW_SYSTEM,          this->registerSystem<ecs::DrawSystem>()));
    this->_systems.insert(std::make_pair(MOVEMENT_SYSTEM,      this->registerSystem<ecs::MovementSystem>()));
    this->_systems.insert(std::make_pair(SELECTOR_SYSTEM,      this->registerSystem<ecs::SelectorSystem>()));
    this->_systems.insert(std::make_pair(CONTROL_MOVE_SYSTEM,  this->registerSystem<ecs::ControlMoveSystem>()));
    this->_systems.insert(std::make_pair(BOUND_SYSTEM,         this->registerSystem<ecs::BoundSystem>()));
    this->_systems.insert(std::make_pair(SCROLL_SYSTEM,        this->registerSystem<ecs::ScrollSystem>()));
    this->_systems.insert(std::make_pair(PARALLAX_SYSTEM,      this->registerSystem<ecs::ParallaxSystem>()));
    this->_systems.insert(std::make_pair(PARALLAX_DRAW_SYSTEM, this->registerSystem<ecs::ParallaxDrawSystem>()));
    this->_systems.insert(std::make_pair(BUTTON_SYSTEM,        this->registerSystem<ecs::ButtonSystem>()));
    this->_systems.insert(std::make_pair(DRAW_TEXT_SYSTEM,     this->registerSystem<ecs::DrawTextSystem>()));
    this->_systems.insert(std::make_pair(ANIMATE_SYSTEM,       this->registerSystem<ecs::AnimateSystem>()));
    this->_systems.insert(std::make_pair(SHOOT_SYSTEM,         this->registerSystem<ecs::ShootSystem>()));
    this->_systems.insert(std::make_pair(COLLISION_SYSTEM,     this->registerSystem<ecs::CollisionSystem>()));
    this->_systems.insert(std::make_pair(AI_SYSTEM,            this->registerSystem<ecs::AISystem>()));
    this->_systems.insert(std::make_pair(TEMPORARY_SYSTEM,     this->registerSystem<ecs::TemporarySystem>()));
    this->_systems.insert(std::make_pair(SPAWN_SYSTEM,         this->registerSystem<ecs::SpawnSystem>()));
    this->_systems.insert(std::make_pair(LIFE_SYSTEM,          this->registerSystem<ecs::LifeSystem>()));
    this->_systems.insert(std::make_pair(UI_RENDER_SYSTEM,     this->registerSystem<ecs::UIRenderSystem>()));
    this->_systems.insert(std::make_pair(SOUND_SYSTEM,         this->registerSystem<ecs::SoundSystem>()));
    this->_systems.insert(std::make_pair(PARTICLES_SYSTEM,     this->registerSystem<ecs::ParticlesSystem>()));
    this->_systems.insert(std::make_pair(SHADER_SYSTEM,        this->registerSystem<ecs::ShaderSystem>()));
    this->_systems.insert(std::make_pair(BULLET_SYSTEM,        this->registerSystem<ecs::BulletSystem>()));

    this->registerComponent<ecs::RLDrawable>();
    this->registerComponent<ecs::Transform>();
    this->registerComponent<ecs::RigidBody>();
    this->registerComponent<ecs::Button>();
    this->registerComponent<ecs::Selector>();
    this->registerComponent<ecs::Control>();
    this->registerComponent<ecs::MoveStat>();
    this->registerComponent<ecs::Bound>();
    this->registerComponent<ecs::Scroll>();
    this->registerComponent<ecs::Shoot>();
    this->registerComponent<ecs::Parallax>();
    this->registerComponent<ecs::RLBackground>();
    this->registerComponent<ecs::RLText>();
    this->registerComponent<ecs::SpriteAnimation>();
    this->registerComponent<ecs::Hitbox>();
    this->registerComponent<ecs::AI>();
    this->registerComponent<ecs::Temporary>();
    this->registerComponent<ecs::Spawn>();
    this->registerComponent<ecs::Alive>();
    this->registerComponent<ecs::UI>();
    this->registerComponent<ecs::SoundEffect>();
    this->registerComponent<ecs::RLParticles>();
    this->registerComponent<ecs::RLShader>();
    this->registerComponent<ecs::Bullet>();
    this->registerComponent<ecs::Bonus>();

    signature.reset();
    signature.set(this->getComponentType<RLDrawable>());
    this->setSystemSignature<DrawSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<Transform>());
    signature.set(this->getComponentType<RigidBody>());
    // signature.set(this->getComponentType<Hitbox>());
    this->setSystemSignature<MovementSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<Control>());
    signature.set(this->getComponentType<Selector>());
    this->setSystemSignature<SelectorSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<Control>());
    signature.set(this->getComponentType<RigidBody>());
    signature.set(this->getComponentType<MoveStat>());
    this->setSystemSignature<ControlMoveSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<Bound>());
    signature.set(this->getComponentType<RigidBody>());
    signature.set(this->getComponentType<Transform>());
    this->setSystemSignature<BoundSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<Scroll>());
    signature.set(this->getComponentType<Transform>());
    this->setSystemSignature<ScrollSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<Parallax>());
    this->setSystemSignature<ParallaxSystem>(signature);
    this->setSystemSignature<ParallaxDrawSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<Button>());
    this->setSystemSignature<ButtonSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<Transform>());
    signature.set(this->getComponentType<RLText>());
    this->setSystemSignature<DrawTextSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<ecs::SpriteAnimation>());
    signature.set(this->getComponentType<ecs::RLDrawable>());
    this->setSystemSignature<AnimateSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<ecs::Transform>());
    signature.set(this->getComponentType<ecs::Shoot>());
    this->setSystemSignature<ShootSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<ecs::Transform>());
    signature.set(this->getComponentType<ecs::Hitbox>());
    this->setSystemSignature<CollisionSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<ecs::AI>());
    this->setSystemSignature<AISystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<ecs::Temporary>());
    this->setSystemSignature<TemporarySystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<ecs::Spawn>());
    signature.set(this->getComponentType<ecs::Transform>());
    this->setSystemSignature<SpawnSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<ecs::Alive>());
    this->setSystemSignature<LifeSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<ecs::UI>());
    this->setSystemSignature<UIRenderSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<ecs::SoundEffect>());
    this->setSystemSignature<SoundSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<ecs::RLParticles>());
    this->setSystemSignature<ParticlesSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<ecs::RLShader>());
    this->setSystemSignature<ShaderSystem>(signature);


    signature.reset();
    signature.set(this->getComponentType<ecs::Bullet>());
    this->setSystemSignature<BulletSystem>(signature);
}
