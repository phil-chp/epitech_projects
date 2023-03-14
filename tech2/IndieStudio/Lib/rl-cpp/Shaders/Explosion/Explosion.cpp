/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo [WSL : Ubuntu]
** File description:
** Explosion
*/

#include "Explosion.hpp"

#define RLIGHTS_IMPLEMENTATION
#include "Shaders/Rlights.h"

rl::Explosion::Explosion(rl::Vector3 cubePos, std::string const &shaderName, rl::Vector4 amp, int maxInstances) : _shader(shaderName)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    if (maxInstances > MAX_INSTANCES)
        maxInstances = MAX_INSTANCES;
    this->_speed = 1;                                 // Speed of jump animation
    this->_groups = 1;                                 // Count of separate groups jumping around
    this->_maxFrames = 0;
    this->_variance = 0.4f;                          // Global variance in jump height
    this->_frameExplosion = 0;                         // Frame counter for Explosion animation
    this->_maxInstances = maxInstances;
    float x = 0.0f, y = 0.0f, z = 0.0f;             // Used for various 3D coordinate & vector ops
    this->_amp = amp;   // Amplitude of jump animation
    this->_center = cubePos;
    this->_mesh.genCube(rl::Cube(cubePos, rl::Vector3(0.1f)));
    // try {
    //     this->_mesh = rl::MeshManager::getInstance().getData(cubePos);
    // } catch (std::exception &e) {
    //     rl::MeshManager::getInstance().insertData(
    // }

    // --------------------------------------------------------------------------------------------
    for (int i = 0; i < this->_maxInstances; i++)
    {
        x = this->_getRandomValue(-0.5f, 0.5f) + this->_center.x; // Scale the cube of particles
        y = this->_getRandomValue(-0.5f, 0.5f) + this->_center.y;
        z = this->_getRandomValue(-0.5f, 0.5f) + this->_center.z;

        this->_translations[i] = MatrixTranslate(x, y, z);

        x = this->_getRandomValue(-1.0f, 1.0f);
        y = this->_getRandomValue(-1.0f, 1.0f);
        z = this->_getRandomValue(-1.0f, 1.0f);

        rl::Vector3 axis(x, y, z, std::string("Normalize"));

        float angle = (float)this->_getRandomValue(0, 10) * DEG2RAD;

        this->_rotationsInc[i].rotate(axis, angle);
        this->_rotations[i] = MatrixIdentity();
    }

    // Get some shader loactions
    // --------------------------------------------------------------------------------------------
    // this->_shader.locs[SHADER_LOC_MATRIX_MVP] = this->_shader.getLocation("mvp");
    // this->_shader.locs[SHADER_LOC_VECTOR_VIEW] = this->_shader.getLocation("viewPos");
    // this->_shader.locs[SHADER_LOC_MATRIX_MODEL] = this->_shader.getLocationAttrib("instanceTransform");

    // Ambient light level
    // --------------------------------------------------------------------------------------------
    int ambientLoc = this->_shader.getLocation("ambient");
    float array[4] = { 0.5f, 0.5f, 0.5f, 1.0f};
    this->_shader.setValue(ambientLoc, array, SHADER_UNIFORM_VEC4);

    CreateLight(LIGHT_DIRECTIONAL, (Vector3){ 50.0f, 50.0f, 0.0f }, rl::Vector3(0.0), rl::Color(252, 65, 3, 255), this->_shader);
    // --------------------------------------------------------------------------------------------

    this->_mesh.material.setShader(this->_shader);
    this->_mesh.material.maps[MATERIAL_MAP_DIFFUSE].color = rl::RL_RED;

}

rl::Explosion::~Explosion()
{
}

void rl::Explosion::start(rl::Vector4 amplitude, int speed, int maxFrames)
{
    this->_frameExplosion = 1;
    this->_speed = speed;
    this->_maxFrames = maxFrames;
    this->_amp = amplitude * 3500.0f;
}

int rl::Explosion::compute(rl::Vector3 cameraPos)
{
    if (this->_frameExplosion > this->_maxFrames) {
        // this->_amp.debug();
        this->_frameExplosion = 0;
        this->_speed = 1;
        this->_amp = rl::Vector4(1.0f);
        return (1);
    }
    this->_frameExplosion++;
    float camPos[3] = { cameraPos.x, cameraPos.y, cameraPos.z };

    this->_shader.setValue(this->_shader.locs[SHADER_LOC_VECTOR_VIEW], camPos, SHADER_UNIFORM_VEC3);
    this->_mesh.material.setShader(this->_shader);

    for (int i = 0; i < this->_maxInstances; ++i) {

        rl::Vector4 amp = (this->_amp / 1.5f) * sinf((float)i * PI * 2.0f) * ((1 - this->_variance) + (this->_variance * (float)(i % 2 / 2)));
        float rand = this->_getRandomValue(-0.5f, 0.5f);
        int nb = (int)round(this->_getRandomValue(0.0f, 4.0f));

        this->_rotations[i] *= this->_rotationsInc[i];

        this->_transforms[i] = MatrixMultiply(this->_rotations[i], this->_translations[i]);
        this->_transforms[i] *= rl::Matrix(
              (nb == 1) ? MatrixTranslate(fabs(amp.x) * rand, 0.0, 0.0)
            : (nb == 2) ? MatrixTranslate(0.0, 0.0, fabs(amp.z) * rand)
            : (nb == 3) ? MatrixTranslate(fabs(amp.y) * -1 * rand, 0.0, 0.0)
            :             MatrixTranslate(0.0, 0.0, fabs(amp.w) * -1 * rand));
    }
    return (0);
}

void rl::Explosion::draw()
{
    ::DrawMeshInstanced(this->_mesh, this->_mesh.material, this->_transforms.data(), this->_maxInstances);
    // ::DrawCubeWires(rl::Vector3(this->_amp.x * SCALING, this->_amp.y * SCALING, this->_amp.z * SCALING), rl::RL_RED);
}
