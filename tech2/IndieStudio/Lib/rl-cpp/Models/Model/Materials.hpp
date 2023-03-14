/*
** EPITECH PROJECT, 2022
** Indie-Studio (Workspace)
** File description:
** Materials
*/

#ifndef MATERIALS_HPP_
    #define MATERIALS_HPP_

namespace rl {
    // Material map index
    enum MaterialMapIndex {
        MAT_ALBEDO    = 0,     // Albedo material (same as: MAT_DIFFUSE)
        MAT_METALNESS,         // Metalness material (same as: MAT_SPECULAR)
        MAT_NORMAL,            // Normal material
        MAT_ROUGHNESS,         // Roughness material
        MAT_OCCLUSION,         // Ambient occlusion material
        MAT_EMISSION,          // Emission material
        MAT_HEIGHT,            // Heightmap material
        MAT_CUBEMAP,           // Cubemap material (NOTE: Uses GL_TEXTURE_CUBE_MAP)
        MAT_IRRADIANCE,        // Irradiance material (NOTE: Uses GL_TEXTURE_CUBE_MAP)
        MAT_PREFILTER,         // Prefilter material (NOTE: Uses GL_TEXTURE_CUBE_MAP)
        MAT_BRDF               // Brdf material
    } ;

    #define MAT_DIFFUSE      MAT_ALBEDO
    #define MAT_SPECULAR     MAT_METALNESS

}

#endif /* !MATERIALS_HPP_ */
