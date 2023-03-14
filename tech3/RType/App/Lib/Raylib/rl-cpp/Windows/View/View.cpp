/*
** EPITECH PROJECT, 2022
** RType
** File description:
** View
*/

#include "Lib/Raylib/rl-cpp/Windows/View/View.hpp"

static void update(rl::Camera3D *camera)
{
    ::UpdateCamera(camera);
}

static void setMode(rl::Camera3D const &camera, int mode)
{
    ::SetCameraMode(camera, mode);
}

static void setPanControl(int keyPan)
{
    ::SetCameraPanControl(keyPan);
}

static void setAltControl(int keyAlt)
{
    ::SetCameraAltControl(keyAlt);
}

static void setSmoothZoomControl(int keySmoothZoom)
{
    ::SetCameraSmoothZoomControl(keySmoothZoom);
}

static void setMoveControls(rl::ViewControls const &controls)
{
    ::SetCameraMoveControls(controls.up,
                          controls.down,
                          controls.left,
                          controls.right,
                          controls.back,
                          controls.front);
}

static void setControls(rl::ViewControls const &controls)
{
    setPanControl(controls.pan);
    setAltControl(controls.alt);
    setSmoothZoomControl(controls.smoothZoom);
    setMoveControls(controls);
}
