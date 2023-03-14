/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Area di lavoro)
** File description:
** Model
*/

#ifndef MODEL_HPP_
#define MODEL_HPP_

#include "Raylib-cpp.hpp"
#include "Drawable/IDrawable.hpp"
#include "Vectors/Vectors.hpp"
#include "Models/Mesh/Mesh.hpp"
#include "Colors/Color.hpp"
#include "Error/Error.hpp"
#include "Colors/Colors.hpp"
#include "Models/Model/Materials.hpp"
#include "Textures/Texture.hpp"
#include "Shapes/Shapes.hpp"
#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>
#include <string>

namespace rl
{
    enum ModelType {
        MODEL_MISSING = -1,
        MODEL_PLAYER_WHITE,
        MODEL_PLAYER_BLACK,
        MODEL_PLAYER_BLUE,
        MODEL_PLAYER_RED,
        MODEL_PLAYER_GREEN,
        MODEL_PLAYER_YELLOW,
        MODEL_CRATE,
        MODEL_PILLAR,
        MODEL_BOMB,
        MODEL_ITEM
    };

    enum ModelAnimationType {
        ANIM_MISSING = -1,
        ANIM_PLAYER,
        ANIM_BOMB
    };

    struct ModelDatas {
        ModelType id;
        std::string const modelPath;
        std::vector<std::pair<MaterialMapIndex, TextureType>> materialTextureMap;
    };

    struct ModelAnimationDatas {
        ModelAnimationType id;
        std::string const modelPath;
        int count;
    };

    // typedef std::vector<ModelData> ModelDatas;

    const ModelDatas DEFAULT_MODEL = ModelDatas{MODEL_MISSING, "Assets/models/missing_model.iqm", {std::make_pair(MAT_DIFFUSE, TEXTURE_MISSING)}};

    const ModelAnimationDatas DEFAULT_MODEL_ANIM = ModelAnimationDatas{ANIM_MISSING, "Assets/models/missing_model.iqm", 0};

    class Model;

    class ModelAnimation : public ::ModelAnimation
    {
    public:
        ModelAnimation(ModelAnimationType const &animType = ANIM_MISSING);
        ModelAnimation(std::string const &fileName, unsigned int animCount)
            : filename(fileName), count(animCount)
        {
            this->animLoad(fileName, animCount);
        }

        void operator=(const ::ModelAnimation &modelAnimation)
        {
            this->boneCount = modelAnimation.boneCount;
            this->frameCount = modelAnimation.frameCount;
            this->bones = modelAnimation.bones;
            this->framePoses = modelAnimation.framePoses;
        }

        //* Custom ---------------------------------------------------------- //

        ~ModelAnimation()
        {
            // this->animUnload();
        }

        // Increment by one n-th animation
        void animIncrement(unsigned int anim, rl::Model &entity);

        // Load animations
        void animLoad(std::string const &fileName, unsigned int animCount) {
            this->_anims = ::LoadModelAnimations(fileName.c_str(), &animCount);
            this->_animIsLoaded = true;
            this->_animCount = animCount;
            this->_animFrame.resize(animCount, 0);
        }

        //* Built-in -------------------------------------------------------- //

        // Unload animation data
        void animUnload()
        {
            ::UnloadModelAnimation(*this);
        }
        // Update model animation pose
        void animUpdate(unsigned int anim, rl::Model &entity);
        // Unload animation array data
        void animUnloadNth(unsigned int count) {
            ::UnloadModelAnimations(this, count);
        }
        // Check model animation skeleton match
        // bool animIsValid() const
        // {
        //     Model model = this->_entity;
        //     return ::IsModelAnimationValid(model, *this);
        // }

        bool animIsLoaded() const
        {
            return (this->_animIsLoaded);
        }

        std::string filename;
        int count;
    private:
        bool _animIsLoaded;
        ::ModelAnimation *_anims;
        unsigned int _animCount;
        std::vector<unsigned int> _animFrame;
    };

    class Model : public IDrawable, public ::Model
    {
    public:
        // explicit Model(::LoadModelFromMesh()) {
        //     : ::Model{}
        //     , position()
        //     , color(RL_WHITE)
        //     , scale(1)
        //     , _isLoaded(true)
        // {}

            // }
            Model(rl::ModelType const &type = rl::MODEL_MISSING);
            explicit Model(std::string const &fileName, std::vector<std::pair<MaterialMapIndex, TextureType> > const &materialTextureMap)
                : ::Model{::LoadModel(fileName.c_str())}
                , position()
                , color(RL_RED)
                , scale(1)
                , _isLoaded(true) {
                    std::for_each(materialTextureMap.begin(), materialTextureMap.end(),
                        [this](std::pair<rl::MaterialMapIndex, rl::TextureType> const &pair) {
                            this->setMaterialTexture(pair.first, pair.second);
                    });
                }
            explicit Model(std::string const &fileName, Vector3 const &pos, Color const &tint = RL_RED, float scale = 1)
                : ::Model{::LoadModel(fileName.c_str())}
                , position(pos)
                , color(tint)
                , scale(scale)
                , _isLoaded(true) {}
            explicit Model(std::string const &fileName, Vector3 const &pos, ::Color const &tint = RED, float scale = 1)
                : ::Model{::LoadModel(fileName.c_str())}
                , position(pos)
                , color(tint)
                , scale(scale)
                , _isLoaded(true) {}
            explicit Model(Mesh const &mesh)
                : ::Model{::LoadModelFromMesh(mesh)}
                , position()
                , color(RL_RED)
                , scale(1)
                , _isLoaded(true) {}

        explicit Model(::Model const &model)
            : ::Model{model}, position(), color(RL_WHITE), scale(1), frame(0), _isLoaded(true), _anim(ANIM_MISSING) {}

        void operator=(::Model const &model)
        {
            *this = model;
            // this->transform = model.transform;
            // this->meshCount = model.meshCount;
            // this->materialCount = model.materialCount;
            // this->meshes = model.meshes;
            // this->materials = model.materials;
            // this->meshMaterial = model.meshMaterial;
            // this->boneCount = model.boneCount;
            // this->bones = model.bones;
            // this->bindPose = model.bindPose;
        }

        //* Custom ---------------------------------------------------------- //

        ~Model()
        {
            // this->unload();
        }

        // Increment by one n-th animation
        void animationIncrement(unsigned int animation) const;

        void setAnimType(ModelAnimationType const &type) {
            this->_anim = type;
        }

        ModelAnimationType getAnimType() const {
            return (this->_anim);
        }

        //* Built-in -------------------------------------------------------- //

        // MANAGEMENT --------------------------------------------------- //

        // Unload model (including meshes) from memory (RAM and/or VRAM)
        void unload();
        // Unload model (but not meshes) from memory (RAM and/or VRAM)
        void unloadKeepMeshes();
        // Compute model bounding box limits (considers all meshes)
        BoundingBox getBoundingBox() const;

        void setMaterialTexture(MaterialMapIndex material, TextureType textureId)
        {
            if (this->_textures.size() != 0 && textureId > rl::TEXTURE_ITEM_BOMB_UP) return;
            rl::Texture texture = rl::TextureManager::getInstance().getData(textureId);
            this->_textures.push_back(texture);
            ::SetMaterialTexture(&this->materials[0], material, texture);
        }

        bool isLoaded() const
        {
            return this->_isLoaded;
        }

        // GENERATION --------------------------------------------------- //

        // Draw a  (with texture if set)
        void draw() const override;
        // Draw a  with extended parameters
        void drawEx(Vector3 const &rotationAxis, float rotationAngle) const;
        // Draw a  wires (with texture if set)
        void drawWires() const;
        // Draw a model wires (with texture if set) with extended parameters
        void drawWiresEx(Vector3 const &rotationAxis, float rotationAngle) const;

        Vector3 position;
        Color color;
        float scale;

        unsigned int frame;
    private:
        std::vector<Texture> _textures;
        bool _isLoaded;
        ModelAnimationType _anim;
    };

    typedef DataManager<ModelAnimation, ModelAnimationType> ModelAnimationManager;

    typedef DataManager<Model, ModelType> ModelManager;

    class AnimatedModel
    {
    public:
        AnimatedModel(ModelType const &type = MODEL_MISSING, ModelAnimationType const &animType = ANIM_MISSING)
            : entity(type), animations(animType)
        {
        }
        Model entity;
        ModelAnimation animations;
    };

}

#endif /* !MODEL_HPP_ */
