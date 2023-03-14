/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** Camera3D
*/

#ifndef CAMERA3D_HPP_
    #define CAMERA3D_HPP_

    #include "Lib/Raylib/rl-cpp/Raylib-cpp.hpp"
    #include "Lib/Raylib/rl-cpp/Vectors/Vectors.hpp"
    #include "Lib/Raylib/rl-cpp/Matrix/Matrix.hpp"
    #include <string>

namespace rl {
    class Camera3D : public ::Camera3D {
        public:
            Camera3D(Camera3D const &camera) : ::Camera3D{camera} {};
            Camera3D(Vector3 const &position = Vector3(0.0f, 30.0f, 12.0f),
                     Vector3 const &target = Vector3(0.0f, 0.0f, 0.0f),
                     Vector3 const &up = Vector3(0.0f, 1.0f, 0.0f),
                     float fovy = 30.0f,
                     CameraProjection const &projection = CAMERA_PERSPECTIVE)
                : ::Camera3D{position, target, up, fovy, projection} {};
            ~Camera3D() = default;

            void operator=(::Camera3D const &camera) {
                this->position = camera.position;
                this->target = camera.target;
                this->up = camera.up;
                this->fovy = camera.fovy;
                this->projection = camera.projection;
            }
            void operator=(Camera3D const &camera) {
                *this = camera;
            }
            void operator=(::Camera3D const &&camera) {
                *this = camera;
            }
            void operator=(Camera3D const &&camera) {
                *this = camera;
            }

            // Getters
            Vector3 getPosition() const {
                return rl::Vector3(this->position);
            }
            Vector3 getTarget() const {
                return rl::Vector3(this->target);
            }
            Vector3 getUp() const {
                return rl::Vector3(this->up);
            }
            float getFovy() const {
                return this->fovy;
            }
            int getProjection() const {
                return this->projection;
            }

            // Setters
            void setPosition(Vector3 const &position) {
                this->position = position;
            }
            void setTarget(Vector3 const &target) {
                this->target = target;
            }
            void setUp(Vector3 const &up) {
                this->up = up;
            }
            void setFovy(float fovy) {
                this->fovy = fovy;
            }
            void setProjection(CameraProjection const &projection) {
                this->projection = projection;
            }

            void update() {
                ::UpdateCamera(this);
            }

            void setMode(int mode) {
                ::SetCameraMode(*this, mode);
            }

            void setPanControl(int keyPan) const
            {
                ::SetCameraPanControl(keyPan);
            }

            void setAltControl(int keyAlt) const
            {
                ::SetCameraAltControl(keyAlt);
            }

            void setSmoothZoomControl(int keySmoothZoom) const
            {
                ::SetCameraSmoothZoomControl(keySmoothZoom);
            }

            void setMoveControls(int keyFront, int keyBack, int keyRight, int keyLeft, int keyUp, int keyDown) const
            {
                ::SetCameraMoveControls(keyFront, keyBack, keyRight, keyLeft, keyUp, keyDown);
            }

            void set(Vector3 const &position,
                     Vector3 const &target,
                     Vector3 const &up,
                     float fovy,
                     CameraProjection const &projection)
            {
                // this->position = position;
                this->position = position;
                this->target = target;
                this->up = up;
                this->fovy = fovy;
                this->projection = projection;
                ::UpdateCamera(this);
            }

        //* Built-in -------------------------------------------------------- //

            // Get camera transform matrix (view matrix)
            Matrix getMatrix()
            {
                return rl::Matrix(::GetCameraMatrix(*this));
            }

            // Get the screen space position for a 3d world space position
            Vector2 getWorldToScreen(Vector3 position)
            {
                return rl::Vector2(::GetWorldToScreen(position, *this));
            }
            // Get size position for a 3d world space position
            Vector2 getWorldToScreenEx(Vector3 position, int width, int height)
            {
                return rl::Vector2(::GetWorldToScreenEx(position, *this, width, height));
            }

    };
}

#endif /* !CAMERA3D_HPP_ */
