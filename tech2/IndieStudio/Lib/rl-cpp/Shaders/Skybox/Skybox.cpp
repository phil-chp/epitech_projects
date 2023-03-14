/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo [WSL : Ubuntu]
** File description:
** Skybox
*/

#include "Skybox.hpp"

rl::Skybox::~Skybox()
{
}

::TextureCubemap rl::Skybox::_genTextureCubemap(const rl::Shader &shader, const rl::Texture &panorama, int size, int format)
{
    TextureCubemap cubemap = { 0 };

    rlDisableBackfaceCulling();     // Disable backface culling to render inside the cube
    unsigned int rbo = rlLoadTextureDepth(size, size, true);
    cubemap.id = rlLoadTextureCubemap(0, size, format);

    unsigned int fbo = rlLoadFramebuffer(size, size);
    rlFramebufferAttach(fbo, rbo, RL_ATTACHMENT_DEPTH, RL_ATTACHMENT_RENDERBUFFER, 0);
    rlFramebufferAttach(fbo, cubemap.id, RL_ATTACHMENT_COLOR_CHANNEL0, RL_ATTACHMENT_CUBEMAP_POSITIVE_X, 0);

    if (rlFramebufferComplete(fbo)) TraceLog(LOG_INFO, "FBO: [ID 330] Framebuffer object created successfully", fbo);

    rlEnableShader(shader.id);

    ::Matrix matFboProjection = MatrixPerspective(90.0*DEG2RAD, 1.0, RL_CULL_DISTANCE_NEAR, RL_CULL_DISTANCE_FAR);
    rlSetUniformMatrix(shader.locs[SHADER_LOC_MATRIX_PROJECTION], matFboProjection);

    ::Matrix fboViews[6] = {
            MatrixLookAt((::Vector3){ 0.0f, 0.0f, 0.0f }, (::Vector3){  1.0f,  0.0f,  0.0f }, (::Vector3){ 0.0f, -1.0f,  0.0f }),
            MatrixLookAt((::Vector3){ 0.0f, 0.0f, 0.0f }, (::Vector3){ -1.0f,  0.0f,  0.0f }, (::Vector3){ 0.0f, -1.0f,  0.0f }),
            MatrixLookAt((::Vector3){ 0.0f, 0.0f, 0.0f }, (::Vector3){  0.0f,  1.0f,  0.0f }, (::Vector3){ 0.0f,  0.0f,  1.0f }),
            MatrixLookAt((::Vector3){ 0.0f, 0.0f, 0.0f }, (::Vector3){  0.0f, -1.0f,  0.0f }, (::Vector3){ 0.0f,  0.0f, -1.0f }),
            MatrixLookAt((::Vector3){ 0.0f, 0.0f, 0.0f }, (::Vector3){  0.0f,  0.0f,  1.0f }, (::Vector3){ 0.0f, -1.0f,  0.0f }),
            MatrixLookAt((::Vector3){ 0.0f, 0.0f, 0.0f }, (::Vector3){  0.0f,  0.0f, -1.0f }, (::Vector3){ 0.0f, -1.0f,  0.0f })
    };

    rlViewport(0, 0, size, size);   // Set viewport to current fbo dimensions

    rlActiveTextureSlot(0);
    rlEnableTexture(panorama.id);

    for (int i = 0; i < 6; i++)
    {
        rlSetUniformMatrix(shader.locs[SHADER_LOC_MATRIX_VIEW], fboViews[i]);
        rlFramebufferAttach(fbo, cubemap.id, RL_ATTACHMENT_COLOR_CHANNEL0, RL_ATTACHMENT_CUBEMAP_POSITIVE_X + i, 0);
        rlEnableFramebuffer(fbo);

        rlClearScreenBuffers();
        rlLoadDrawCube();
    }

    rlDisableShader();          // Unbind shader
    rlDisableTexture();         // Unbind texture
    rlDisableFramebuffer();     // Unbind framebuffer
    rlUnloadFramebuffer(fbo);   // Unload framebuffer (and automatically attached depth texture/renderbuffer)

    rlViewport(0, 0, rlGetFramebufferWidth(), rlGetFramebufferHeight());
    rlEnableBackfaceCulling();
    //------------------------------------------------------------------------------------------

    cubemap.width = size;
    cubemap.height = size;
    cubemap.mipmaps = 1;
    cubemap.format = format;

    return cubemap;
}

void rl::Skybox::draw() const
{
    rlDisableBackfaceCulling();
    rlDisableDepthMask();

    this->_model.draw();

    rlEnableBackfaceCulling();
    rlEnableDepthMask();
}
