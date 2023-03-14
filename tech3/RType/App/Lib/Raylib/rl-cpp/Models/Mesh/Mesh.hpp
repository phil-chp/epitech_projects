/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** Mesh
*/

#ifndef MESH_HPP_
    #define MESH_HPP_

    #include "Lib/Raylib/rl-cpp/Raylib-cpp.hpp"
    #include "Lib/Raylib/rl-cpp/Error/Error.hpp"
    #include "Lib/Raylib/rl-cpp/Drawable/IDrawable.hpp"
    #include "Lib/Raylib/rl-cpp/Vectors/Vectors.hpp"
    #include "Lib/Raylib/rl-cpp/Matrix/Matrix.hpp"
    #include "Lib/Raylib/rl-cpp/Models/Material/Material.hpp"
    #include "Lib/Raylib/rl-cpp/Collisions/Collisions.hpp"
    #include <string>

namespace rl {
    // typedef std::pair<int, int> Num; // TODO: what

    class Mesh : public IDrawable, public ::Mesh {
        public:
            // explicit Mesh(rl::Vector3 const &vec = rl::Vector3(0.0f));
            explicit Mesh(Vector3 const & = Vector3(0.0f)) : ::Mesh{/*rl::MeshManager::getInstance().getData("cube")*/::GenMeshCube(1.0f, 1.0f, 1.0f)}, material(), transform(), _isLoaded(true) {};
            // explicit Mesh(Vector3 const &pos, Material const &texture = Material()) : ::Mesh{::GenMeshCube(1.0f, 1.0f, 1.0f)}, material(texture), transform(), _isLoaded(true) {};
            explicit Mesh(Material const &texture) : ::Mesh{::GenMeshCube(1.0f, 1.0f, 1.0f)}, material(texture), transform(), _isLoaded(true) {};
            explicit Mesh(::Mesh const &mesh) : ::Mesh{mesh}, material(), transform(), _isLoaded(true) {};

            void operator=(::Mesh const &mesh) {
                this->vertexCount = mesh.vertexCount;
                this->triangleCount = mesh.triangleCount;
                this->vertices = mesh.vertices;
                this->texcoords = mesh.texcoords;
                this->texcoords2 = mesh.texcoords2;
                this->normals = mesh.normals;
                this->tangents = mesh.tangents;
                this->colors = mesh.colors;
                this->indices = mesh.indices;
                this->animVertices = mesh.animVertices;
                this->animNormals = mesh.animNormals;
                this->boneIds = mesh.boneIds;
                this->boneWeights = mesh.boneWeights;
                this->vaoId = mesh.vaoId;
                this->vboId = mesh.vboId;
            }

        //* Custom ---------------------------------------------------------- //

            ~Mesh() = default;

            static Mesh getDefaultMesh();

        //* Built-in -------------------------------------------------------- //

            // GENERATION --------------------------------------------------- //

            // Generate polygonal mesh
            void genPoly(int sides, float radius);
            // Generate plane mesh (with subdivisions)
            void genPlane(float width, float length, int resX, int resZ);
            // Generate cuboid mesh
            void genCube(Cube const &cube);
            // Generate sphere mesh (standard sphere)
            void genSphere(Sphere const &sphere, int slices, int stacks);
            // Generate half-sphere mesh (no bottom cap)
            void genHemiSphere(Sphere const &sphere, int slices, int stacks);
            // Generate cylinder mesh
            void genCylinder(Cylinder const &cylinder);
            // Generate cone/pyramid mesh
            void genCone(Cylinder const &cylinder);
            // Generate torus mesh
            void genTorus(float radius, float size, int radSeg, int sides);
            // Generate trefoil knot mesh
            void genKnot(float radius, float size, int radSeg, int sides);
            // Generate heightmap mesh from image data
            void genHeightmap(Image const &heightmap, Vector3 const &size);
            // Generate cubes-based map mesh from image data
            void genCubicmap(Image const &cubicmap, Vector3 const &cubeSize);

            // MANAGEMENT --------------------------------------------------- //

            // Unload mesh data from CPU and GPU
            void unload();
            // Upload mesh vertex data in GPU and provide VAO/VBO ids
            void upload(bool const &dynamic);
            // Update mesh vertex data in GPU for a specific buffer index
            void updateBuffer(int index, void *data, int dataSize, int offset) const;
            // Draw a 3d mesh with material and transform
            void draw() const override;
            // Export mesh data to file, returns true on success
            bool exportMesh(std::string const &fileName) const;
            // Compute mesh bounding box limits
            BoundingBox getBoundingBox() const;
            // Compute mesh tangents
            void genTangents();
            // Compute mesh binormals
            void genBinormals();
            // Get collision info between ray and mesh
            RayCollision getRayCollision(Ray const &ray) const;
            // apply transformation to mesh
            void applyTransform3D(Matrix const &transform);

            bool isLoaded() const {
                return this->_isLoaded;
            }

            //* Attributes --------------------------------------------------- //

            Material material;
            Matrix transform;

        private:
            bool _isLoaded;

    };

    // typedef DataManager<rl::Mesh, int> MeshManager;

}



#endif /* !MESH_HPP_ */
