/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** Mesh
*/

#include "Mesh.hpp"

// GENERATION --------------------------------------------------------------- //

// template <>
// template <>
// void rl::MeshManager::insertData<rl::Vector3 const &>(rl::Vector3 const &data)
// {
//     if (this->_datas.find(data) != this->_datas.end()) {
//         throw(rl::Error("Mesh \"" + data.debugString() + "\" already exists.", "MeshManager::insertData"));
//     }
//     rl::Mesh mesh(data);
//     this->_datas.insert(std::make_pair(data, mesh));
// }

// template <>
// rl::Mesh rl::MeshManager::getData(rl::Vector3 const &name)
// {
//     if (this->_datas.find(name) == this->_datas.end()) {
//         std::cout << "Error :::" << std::endl;
//         throw(rl::Error("Mesh \"" + name + "\" doesn't exist.", "MeshManager::insertData"));
//     }
//     rl::Mesh mesh(this->_datas[name]);
//     return (mesh);
// }

// template <>
// rl::MeshManager::~DataManager<rl::Mesh, rl::Vector3>()
// {
//     for (auto pair : this->_datas) {
//         pair.second.unload();
//     }
// }

// rl::Mesh::Mesh(std::string const &name) : ::Mesh(rl::MeshManager::getInstance().getData(name))
// {
// };

void rl::Mesh::genPoly(int sides, float radius)
{
    this->unload();
    *this = ::GenMeshPoly(sides, radius);
}

void rl::Mesh::genPlane(float width, float length, int resX, int resZ)
{
    this->unload();
    *this = ::GenMeshPlane(width, length, resX, resZ);
}

void rl::Mesh::genCube(Cube const &cube)
{
    this->unload();
    *this = ::GenMeshCube(cube.size.x, cube.size.y, cube.size.z);
}


void rl::Mesh::genSphere(Sphere const &sphere, int slices, int stacks)
{
    this->unload();
    *this = ::GenMeshSphere(sphere.radius, slices, stacks);
}

void rl::Mesh::genHemiSphere(Sphere const &sphere, int slices, int stacks)
{
    this->unload();
    *this = ::GenMeshHemiSphere(sphere.radius, slices, stacks);
}

void rl::Mesh::genCylinder(Cylinder const &cylinder)
{
    this->unload();
    *this = ::GenMeshCylinder(cylinder.radiusTop, cylinder.size.y, cylinder.slices);
}

void rl::Mesh::genCone(Cylinder const &cylinder)
{
    this->unload();
    *this = ::GenMeshCone(cylinder.radiusTop, cylinder.size.y, cylinder.slices);
}

void rl::Mesh::genTorus(float radius, float size, int radSeg, int sides)
{
    this->unload();
    *this = ::GenMeshTorus(radius, size, radSeg, sides);
}

void rl::Mesh::genKnot(float radius, float size, int radSeg, int sides)
{
    this->unload();
    *this = ::GenMeshKnot(radius, size, radSeg, sides);
}

void rl::Mesh::genHeightmap(Image const &heightmap, rl::Vector3 const &size)
{
    this->unload();
    *this = ::GenMeshHeightmap(heightmap, size);
}

void rl::Mesh::genCubicmap(Image const &cubicmap, rl::Vector3 const &cubeSize)
{
    this->unload();
    *this = ::GenMeshCubicmap(cubicmap, cubeSize);
}

// MANAGEMENT --------------------------------------------------------------- //

void rl::Mesh::unload()
{
    if (_isLoaded) {
        ::UnloadMesh(*this);
        _isLoaded = false;
    }
}

void rl::Mesh::upload(bool const &dynamic)
{
    if (!_isLoaded) {
        throw rl::Error("Mesh is not loaded", "Mesh::upload");
    }
    ::UploadMesh(this, dynamic);
}

void rl::Mesh::updateBuffer(int index, void *data, int dataSize, int offset) const
{
    if (!_isLoaded) {
        throw rl::Error("Mesh is not loaded", "Mesh::upload");
    }
    ::UpdateMeshBuffer(*this, index, data, dataSize, offset);
}

void rl::Mesh::draw() const
{
    if (!_isLoaded) {
        throw rl::Error("Mesh is not loaded", "Mesh::draw");
    }
    ::DrawMesh(*this, material, transform);
}

bool rl::Mesh::exportMesh(std::string const &fileName) const
{
    if (!_isLoaded) {
        throw rl::Error("Mesh is not loaded", "Mesh::exportMesh");
    }
    return (::ExportMesh(*this, fileName.c_str()));
}

rl::BoundingBox rl::Mesh::getBoundingBox() const
{
    if (!_isLoaded) {
        throw rl::Error("Mesh is not loaded", "Mesh::getBoundingBox");
    }
    return (rl::BoundingBox(::GetMeshBoundingBox(*this)));
}

void rl::Mesh::genTangents()
{
    if (!_isLoaded) {
        throw rl::Error("Mesh is not loaded", "Mesh::genTangents");
    }
    ::GenMeshTangents(this);
}

void rl::Mesh::genBinormals()
{
    if (!_isLoaded) {
        throw rl::Error("Mesh is not loaded", "Mesh::genBinormals");
    }
    ::GenMeshBinormals(this);
}

void rl::Mesh::applyTransform3D(Matrix const &trans)
{
    this->transform = trans;
}

rl::RayCollision rl::Mesh::getRayCollision(rl::Ray const &ray) const
{
    if (!_isLoaded) {
        throw rl::Error("Mesh is not loaded", "Mesh::getRayCollision");
    }
    return (rl::RayCollision(::GetRayCollisionMesh(ray, *this, transform)));
}

rl::Mesh rl::Mesh::getDefaultMesh()
{
    rl::Mesh mesh;
    mesh.genCube(rl::Cube());
    return mesh;
}
