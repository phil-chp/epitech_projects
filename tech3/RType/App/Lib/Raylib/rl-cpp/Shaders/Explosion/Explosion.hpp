/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Explosion
*/

#ifndef EXPLOSION_HPP_
    #define EXPLOSION_HPP_

    #include "Lib/Raylib/rl-cpp/Raylib.hpp"
    #include <exception>
    #include <string>

    #define MAX_INSTANCES  10000
    #define SCALING        5.0f

namespace rl {
    class Explosion
    {
        public:
            Explosion(Vector3 cubePos, std::string const &shaderName = "ExploShader", Vector4 amp = Vector4(0.1f, 0.1f, 0.1f, 0.1f), int maxInstances = 4000);
            // Explosion(Explosion const &other) : _shader(other._shader), _maxInstances(other._maxInstances), _cubeSize(other._cubeSize), _cubePos(other._cubePos), _instances(other._instances), _time(other._time), _started(other._started), _done(other._done) {
            //     std::cout << "Copy Constructor Explosion" << std::endl;
            // }
            ~Explosion();
            void start(Vector4 amplitude, int speed = 75, int maxFrames = 50);
            int compute(Vector3 cameraPos);
            void draw();

            // void operator=(rl::Explosion const &explosion)
            // {
            //     this->_shader = explosion._shader;
            //     this->_mesh = explosion._mesh;
            //     this->_translations = explosion._translations;
            //     this->_rotations = explosion._rotations;
            //     this->_rotationsInc = explosion._rotationsInc;
            //     this->_center = explosion._center;
            //     this->_speed = explosion._speed;
            //     this->_groups = explosion._groups;
            //     this->_maxFrames = explosion._maxFrames;
            //     this->_variance = explosion._variance;
            //     this->_frameExplosion = explosion._frameExplosion;
            //     this->_maxInstances = explosion._maxInstances;
            // }

        private:

            float _getRandomValue(float min, float max) {
                return min + (rand() / (float)RAND_MAX) * (max - min);
            }



            int _speed;
            int _groups;
            int _maxInstances;
            Vector4 _amp;
            float _variance;
            int _frameExplosion;
            int _maxFrames;
            Mesh _mesh;
            Vector3 _center;
            std::array<Matrix, MAX_INSTANCES> _rotations;    // Rotation state of instances
            std::array<Matrix, MAX_INSTANCES> _rotationsInc; // Per-frame rotation animation of instances
            std::array<Matrix, MAX_INSTANCES> _translations; // Locations of instances
            std::array<Matrix, MAX_INSTANCES> _transforms;   // Instance transforms
            Shader _shader;



    };
}




#endif /* !EXPLOSION_HPP_ */
