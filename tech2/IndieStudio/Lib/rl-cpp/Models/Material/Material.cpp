/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** Material
*/

#include "Material.hpp"

// Unload material from GPU memory (VRAM)

// template <>
// void rl::MaterialManager::insertData<rl::MaterialDatas const &>(rl::MaterialDatas const &data)
// {

//     if (this->_datas.find(data.first) != this->_datas.end()) {
//         throw(rl::Error("Material \"" + data.first + "\" already exists.", "MaterialManager::insertData"));
//     }

//     rl::Material material(data.first, data.second);

//     this->_datas.insert(std::make_pair(data.first, material));
// }

void rl::Material::unload()
{
    if (_isLoaded) {
        ::UnloadMaterial(*this);
        _isLoaded = false;
    }
}

// Set texture for a material map type (MATERIAL_MAP_DIFFUSE, MATERIAL_MAP_SPECULAR...)
void rl::Material::setTexture(int mapType, Texture2D const &texture)
{
    ::SetMaterialTexture(this, mapType, texture);
}

// Set material for a mesh
// void rl::Material::setModelMesh(rl::Model model, int meshId, int materialId)
// {
//     ::SetModelMeshMaterial(&model, meshId, materialId);
// }
