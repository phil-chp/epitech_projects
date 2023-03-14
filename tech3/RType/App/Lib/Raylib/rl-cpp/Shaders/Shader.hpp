/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Shader
*/

#ifndef SHADER_HPP_
    #define SHADER_HPP_

    #include "Lib/Raylib/rl-cpp/Raylib-cpp.hpp"
    #include "Lib/Raylib/rl-cpp/DataManager.hpp"
    #include "Lib/Raylib/rl-cpp/Error/Error.hpp"
    #include "Lib/Raylib/rl-cpp/Vectors/Vectors.hpp"
    #include "Lib/Raylib/rl-cpp/Colors/Colors.hpp"
    #include <array>
    #include <string>

namespace rl {

    // typedef std::array<std::string const, 3> ShaderDatas;
    // const ShaderDatas EXPLOSION_SHADER_DATAS = {"Lib/glsl330/base_lighting_instanced.vs",  "Lib/glsl330/lighting.fs", "ExploShader"};

    class Shader : public ::Shader {
        public:
            explicit Shader(std::string const &shaderName = "ExploShader");
            // Load shader from files and bind default locations
            explicit Shader(std::string vsFileName, std::string fsFileName)
                : ::Shader{::LoadShader(vsFileName.c_str(), fsFileName.c_str())}
                , _isLoaded(true)
            {};
            // Load shader from code strings and bind default locations
            explicit Shader(std::array<std::string, 2> args) : ::Shader{::LoadShaderFromMemory(args[0].c_str(), args[0].c_str())}, _isLoaded(true) {};
            // Copy constructor
            // explicit Shader(Shader const &Shader) : ::Shader{Shader}, _isLoaded(true) {};
            explicit Shader(::Shader const &Shader) : ::Shader{Shader}, _isLoaded(true) {};

            void operator=(::Shader const &shader) {
                this->id = shader.id;
                this->locs = shader.locs;
            }
        //* Custom ---------------------------------------------------------- //

            ~Shader() {
                // if (_isLoaded)
                //     this->unload();
            }

        //* Built-in -------------------------------------------------------- //
            int getLocation(std::string uniformName);          // Get shader uniform location
            int getLocationAttrib(std::string attribName);     // Get shader attribute location
            void setValue(int locIndex, const void *value, int uniformType);               // Set shader uniform value
            void setValueV(int locIndex, const void *value, int uniformType, int count);   // Set shader uniform value vector
            void setValueMatrix(int locIndex, Matrix mat);         // Set shader uniform value (matrix 4x4)
            void setValueTexture(int locIndex, Texture2D texture); // Set shader uniform value for texture (sampler2d)
            void unload();                                       // Unload shader from GPU memory (VRAM)

            bool isLoaded() const {
                return this->_isLoaded;
            }

        private:
            bool _isLoaded;
    };
    // typedef DataManager<rl::Shader, std::string> ShaderManager;
}

#endif /* !SHADER_HPP_ */
