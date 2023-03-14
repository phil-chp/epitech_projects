/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** Material
*/

#ifndef MATERIAL_HPP_
    #define MATERIAL_HPP_

    #include "Raylib-cpp.hpp"
    #include "DataManager.hpp"
    #include <string>
    #include <vector>
    #include <iostream>
    #include "Error/Error.hpp"

namespace rl {
    // typedef std::pair<std::string const &, std::vector<int> const &> MaterialDatas;
    class Material : public ::Material {
        public:
            Material() : ::Material{::LoadMaterialDefault()}, _isLoaded(true) {};

            explicit Material(std::string const &fileName, std::vector<int> materialCount)
                : ::Material{*(::LoadMaterials(fileName.c_str(), materialCount.data()))}, _isLoaded(true) {}

            void operator=(const ::Material& material) {
                this->shader = material.shader;
                this->maps = material.maps;
                this->params[0] = material.params[0];
                this->params[1] = material.params[1];
                this->params[2] = material.params[2];
                this->params[3] = material.params[3];
            }

        //* Custom ---------------------------------------------------------- //

            ~Material() {
                // if (_isLoaded) {
                //     this->unload();
                // }
            }

        //* Built-in -------------------------------------------------------- //

            // Unload material from GPU memory (VRAM)
            void unload();
            // Set texture for a material map type (MATERIAL_MAP_DIFFUSE, MATERIAL_MAP_SPECULAR...)
            void setTexture(int mapType, Texture2D const &texture);

            void setShader(::Shader const &shaders) {
                this->shader = shaders;
            }
            // Set material for a mesh
            // void setModelMesh(Model model, int meshId, int materialId) const;

            bool isLoaded() const {
                return _isLoaded;
            }

            private:
                bool _isLoaded;
    };

    // typedef DataManager<rl::Material> MaterialManager;
}

#endif /* !MATERIAL_HPP_ */
