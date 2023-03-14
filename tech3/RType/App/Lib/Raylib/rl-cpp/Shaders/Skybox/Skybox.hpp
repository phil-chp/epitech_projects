/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Skybox
*/

#ifndef SKYBOX_HPP
    #define SKYBOX_HPP

    #include "Lib/Raylib/rl-cpp/Raylib.hpp"
    #include "rlgl.h"
    #include "Lib/Raylib/rl-cpp/Models/Models.hpp"
    #include "Lib/Raylib/rl-cpp/Shaders/Shaders.hpp"
    #include "Lib/Raylib/rl-cpp/Textures/Textures.hpp"
    #include <exception>
    #include <string>
    #include <utility>
    #include <memory>

namespace rl {
    class Skybox {
        public:
            Skybox(std::pair<std::string, std::string> const &pathFirstShader,
                   std::pair<std::string, std::string> const &pathSecondShader,
                   std::string const &path,
                   bool useHdr = false)
                : _model(rl::Mesh::getDefaultMesh())
                , _shdrCubemap(Shader(pathSecondShader.first, pathSecondShader.second))
                , _shader(Shader(pathFirstShader.first, pathFirstShader.second))
                , _texture(Texture::initTextureFromPath(path))
            {
                int array1 = MATERIAL_MAP_CUBEMAP;
                int one = 1;
                int zero = 0;

                this->_shader.setValue(this->_shader.getLocation("environmentMap"), &array1, SHADER_UNIFORM_INT);
                this->_shader.setValue(this->_shader.getLocation("doGamma"),  &one, SHADER_UNIFORM_INT);
                this->_shader.setValue(this->_shader.getLocation("vflipped"), &one, SHADER_UNIFORM_INT);
                this->_model.materials[0].shader = this->_shader;

                this->_shdrCubemap.setValue(this->_shdrCubemap.getLocation("equirectangularMap"), &zero, SHADER_UNIFORM_INT);

                if (useHdr) {
                    this->_model.materials[0].maps[MATERIAL_MAP_CUBEMAP].texture        \
                        = this->_genTextureCubemap(this->_shdrCubemap, this->_texture,  \
                        1024, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
                } else {
                    Image img(path, Vector2(0.0, 0.0));
                    this->_model.materials[0].maps[MATERIAL_MAP_CUBEMAP].texture        \
                        = ::LoadTextureCubemap(img, CUBEMAP_LAYOUT_AUTO_DETECT);
                                                 // CUBEMAP_LAYOUT_PANORAMA
                }
            }
            ~Skybox();

            //* Getters ---------------------------------------------------------- //

            ::Model const &getModel() const {
                return this->_model;
            }

            //* Methods ---------------------------------------------------------- //

            void draw() const;

        private:
            // TextureCubemap _genTextureCubemap(const Shader &shader, const Texture &panorama, int size, int format);
            ::TextureCubemap _genTextureCubemap(const Shader &shader, const Texture &panorama, int size, int format);

            Model _model;
            Shader _shdrCubemap;
            Shader _shader;
            Texture _texture;

    };
}

#endif
