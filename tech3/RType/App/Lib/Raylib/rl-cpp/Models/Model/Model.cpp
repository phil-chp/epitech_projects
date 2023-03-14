/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Model
*/

#include "Lib/Raylib/rl-cpp/Models/Model/Model.hpp"

// MODEL ANIMATION MANAGER -------------------------------------------------- //

// template <>
// template <>
// void rl::ModelAnimationManager::insertData<rl::ModelAnimationDatas const&>(rl::ModelAnimationDatas const &data)
// {

//     if (this->_datas.find(data.id) != this->_datas.end()) {
//         throw(rl::Error("Model \"" + std::to_string(data.id) + "\" already exists.", "ModelManager::insertData"));
//     }

//     rl::ModelAnimation modelAnims(data.modelPath, data.count);
//     this->_datas.insert(std::make_pair(data.id, modelAnims));
// }

// template <>
// rl::ModelAnimation rl::ModelAnimationManager::getData(rl::ModelAnimationType const &id)
// {
//     if (this->_datas.find(id) == this->_datas.end()) {
//         throw(rl::Error("ModelAnimation \"" + std::to_string(id) + "\" doesn't exist.", "ModelManager::getData"));
//     }
//     rl::ModelAnimation modelAnim(this->_datas[id]);
//     return (modelAnim);
// }

// template <>
// rl::ModelAnimationManager::~DataManager<rl::ModelAnimation, rl::ModelAnimationType>()
// {
//     for (auto pair : this->_datas) {
//         pair.second.animUnload();
//     }
// }

// MODEL MANAGER ------------------------------------------------------------ //

// template <>
// template <>
// void rl::ModelManager::insertData<rl::ModelDatas const &>(rl::ModelDatas const &data)
// {

//     if (this->_datas.find(data.id) != this->_datas.end()) {
//         throw(rl::Error("Model \"" + std::to_string(data.id) + "\" already exists.", "ModelManager::insertData"));
//     }

//     rl::Model model(data.modelPath, data.materialTextureMap);
//     this->_datas.insert(std::make_pair(data.id, model));
// }

// template <>
// rl::Model rl::ModelManager::getData(rl::ModelType const &id)
// {
//     if (this->_datas.find(id) == this->_datas.end()) {
//         throw(rl::Error("Model \"" + std::to_string(id) + "\" doesn't exist.", "ModelManager::insertData"));
//     }
//     rl::Model model(this->_datas[id]);
//     return (model);
// }

// template <>
// rl::ModelManager::~DataManager<rl::Model, rl::ModelType>()
// {
//     for (auto pair : this->_datas) {
//         pair.second.unload();
//     }
// }

// MODEL ANIMATION ---------------------------------------------------------- //

rl::ModelAnimation::ModelAnimation(rl::ModelAnimationType const &animType)
    : ::ModelAnimation{rl::ModelAnimationManager::getInstance().getData(animType)}
{
    this->animLoad(
        rl::ModelAnimationManager::getInstance().getData(animType).filename,
        rl::ModelAnimationManager::getInstance().getData(animType).count
    );
}

void rl::ModelAnimation::animIncrement(unsigned int anim, rl::Model &entity) {
    if (!this->_animIsLoaded) {
        throw rl::Error("ModelAnimation is not loaded", "ModelAnimation::increment");
    }
    if (anim > this->_animCount) {
        throw rl::Error("ModelAnimation out of range", "ModelAnimation::increment");
    }
    this->animUpdate(anim, entity);
    entity.frame++;
    if (this->_animFrame[anim] >= (unsigned)this->_anims[anim].frameCount) {
        this->_animFrame[anim] = 0;
    }
}

void rl::ModelAnimation::animUpdate(unsigned int anim, rl::Model &entity) {
    if (!this->_animIsLoaded) {
        throw rl::Error("ModelAnimation is not loaded", "ModelAnimation::animUpdate");
    }
    ::UpdateModelAnimation(entity, this->_anims[anim], entity.frame);
}

// MODEL -------------------------------------------------------------------- //

rl::Model::Model(rl::ModelType const &type)
    : ::Model{rl::ModelManager::getInstance().getData(type)}
    , position()
    , color(RL_WHITE)
    , scale(1)
    , _isLoaded(true)
{}

void rl::Model::unload()
{
    if (this->_isLoaded) {
        this->_isLoaded = false;
        if (this->meshes != nullptr || this->materials != nullptr) {
            ::UnloadModel(*this);
            this->meshes = nullptr;
            this->materials = nullptr;
        }
    }
}

void rl::Model::unloadKeepMeshes()
{
    if (_isLoaded) {
        // this->animUnload();
        ::UnloadModelKeepMeshes(*this);
        _isLoaded = false;
    }
}

rl::BoundingBox rl::Model::getBoundingBox() const
{
    if (!_isLoaded) {
        throw rl::Error("Model is not loaded", "Model::getBoundingBox");
    }
    return rl::BoundingBox(::GetModelBoundingBox(*this));
}


void rl::Model::draw() const
{
    if (!this->_isLoaded) {
        throw rl::Error("Model is not loaded", "Model::getBoundingBox");
    }
    ::DrawModel(*this, this->position, this->scale, this->color);
}

void rl::Model::drawEx(rl::Vector3 const &rotationAxis, float rotationAngle) const
{
    if (!this->_isLoaded) {
        throw rl::Error("Model is not loaded", "Model::getBoundingBox");
    }
    Vector3 modelScale(this->scale);
    ::DrawModelEx(*this, this->position, rotationAxis, rotationAngle, modelScale, this->color);
}

void rl::Model::drawWires() const
{
    if (!this->_isLoaded) {
        throw rl::Error("Model is not loaded", "Model::getBoundingBox");
    }
    ::DrawModelWires(*this, position, scale, color);
}

void rl::Model::drawWiresEx(rl::Vector3 const &rotationAxis, float rotationAngle) const
{
    if (!this->_isLoaded) {
        throw rl::Error("Model is not loaded", "Model::getBoundingBox");
    }
    Vector3 modelScale(this->scale);
    ::DrawModelWiresEx(*this, this->position, rotationAxis, rotationAngle, modelScale, this->color);
}
