/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** Camera2D
*/

#ifndef CAMERA2D_HPP_
    #define CAMERA2D_HPP_

    #include "Raylib-cpp.hpp"
    #include "Matrix/Matrix.hpp"
    #include "Vectors/Vectors.hpp"
    #include <string>

namespace rl {
    class Camera2D : public ::Camera2D {
        public:
            Camera2D(Vector2 const &offset = Vector2(0.0f),
                     Vector2 const &target = Vector2(0.0f),
                     float rotation = 0.0f,
                     float zoom = 1.0f)
                : ::Camera2D{offset, target, rotation, zoom} {};
            Camera2D(rl::Camera2D const &camera)
                : ::Camera2D{camera} {};

            void operator=(::Camera2D const &camera) {
                this->offset = camera.offset;
                this->target = camera.target;
                this->rotation = camera.rotation;
                this->zoom = camera.zoom;
            }
            void operator=(Camera2D const &camera) {
                *this = camera;
            }

            // Getters
            Vector2 getOffset() const {
                return rl::Vector2(this->offset);
            }
            Vector2 getTarget() const {
                return rl::Vector2(this->target);
            }
            float getRotation() const {
                return this->rotation;
            }
            float getZoom() const {
                return this->zoom;
            }
            // Setters
            void setOffset(Vector2 const &offset) {
                this->offset = offset;
            }
            void setTarget(Vector2 const &target) {
                this->target = target;
            }
            void setRotation(float rotation) {
                this->rotation = rotation;
            }
            void setZoom(float zoom) {
                this->zoom = zoom;
            }

            void set(Vector2 const &offset, Vector2 const &target, float rotation, float zoom) {
                this->offset = offset;
                this->target = target;
                this->rotation = rotation;
                this->zoom = zoom;
            }

            ~Camera2D() = default;

        //* Built-in ---------------------------------------------------------- //
            // Get camera 2d transform matrix
            Matrix getMatrix2D()
            {
                return rl::Matrix(::GetCameraMatrix2D(*this));
            }
            // Get the world space position for a 2d camera screen space position
            Vector2 getScreenToWorld2D(Vector2 position)
            {
                return rl::Vector2(::GetScreenToWorld2D(position, *this));
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

    };
}
#endif /* !CAMERA2D_HPP_ */
