/*
** EPITECH PROJECT, 2022
** RType
** File description:
** View
*/

#ifndef CAMERA_HPP_
    #define CAMERA_HPP_

    #include "Lib/Raylib/rl-cpp/Raylib-cpp.hpp"
    #include "Lib/Raylib/rl-cpp/Windows/Keyboard/Keyboard.hpp"
    #include "Lib/Raylib/rl-cpp/Windows/Camera/Camera3D.hpp"
    // #include "Lib/Raylib/rl-cpp/Windows/Keyboard/KeyboardKeys.hpp"
    #include <array>


namespace rl {
    struct ViewControls {
        void setControls(int pan, int alt, int smoothZoom) {
            this->pan        = pan;
            this->alt        = alt;
            this->smoothZoom = smoothZoom;
        }

        void setMoveControls(int up, int down, int left, int right, int back, int front) {
            this->up    = up;
            this->down  = down;
            this->left  = left;
            this->right = right;
            this->back  = back;
            this->front = front;
        }

        int pan, alt, smoothZoom;
        int up, down, left, right, back, front;
    };

    class View {
        public:

        //* Custom ---------------------------------------------------------- //

        //* Built-in -------------------------------------------------------- //

            // Update camera position for selected mode
            static void update(rl::Camera3D *camera);
            // Set View mode (multiple View modes available)
            static void setMode(rl::Camera3D const &camera, int mode);
            // Set View pan key to combine with mouse movement (free View)
            static void setPanControl(int keyPan);
            // Set View alt key to combine with mouse movement (free View)
            static void setAltControl(int keyAlt);
            // Set View smooth zoom key to combine with mouse (free View)
            static void setSmoothZoomControl(int keySmoothZoom);
            // Set camera move controls (1st person and 3rd person cameras)
            static void setMoveControls(ViewControls const &control);

            // Set View control keys
            static void setControls(ViewControls const &control);

    };
}

#endif /* !CAMERA_HPP_ */
