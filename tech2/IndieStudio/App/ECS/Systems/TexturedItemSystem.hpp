/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** TexturedItemSystem
*/

#ifndef TEXTUREDITEMSYSTEM_HPP_
#define TEXTUREDITEMSYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"
    #include "Raylib.hpp"
    #include <unordered_map>

namespace ecs {

    typedef std::unordered_map<int, int> TextureMap;

    class TexturedItemSystem : public ASystem {
        public:
            TexturedItemSystem() = default;
            ~TexturedItemSystem() = default;

            void update(float dt) const final;

        private:
            TextureMap const getTextureMap() const;
    };
}
#endif /* !TEXTUREDITEMSYSTEM_HPP_ */
