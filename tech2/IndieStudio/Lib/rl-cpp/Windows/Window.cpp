/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** Window
*/

#include "Window.hpp"

// WINDOW MAIN -------------------------------------------------------------- //

void rl::Window::init()
{
    if (!this->_isOpen) {
        ::InitWindow(this->_width, this->_height, this->_title.c_str());
        ::InitAudioDevice();
        ::SetMasterVolume(0.25f);
        this->_isOpen = true;
    } else {
        throw rl::Error("Window is already open", "Window::initWindow");
    }
}

void rl::Window::close()
{
    if (this->_isOpen && !this->_exitWindow) {
        ::CloseWindow();
        this->_isOpen = false;
    }
}

void rl::Window::exit()
{
    this->_exitWindow = true;
}

bool rl::Window::isOpen() const
{
    return (this->_isOpen);
}

bool rl::Window::shouldClose()
{
    return (::WindowShouldClose());
}

bool rl::Window::shouldExit()
{
    return (this->_exitWindow);
}

void rl::Window::clearBackground() const
{
    if (!this->_isOpen)
        throw rl::Error("Window is not open, could not clear background", "Window::clearBackground");
    ::ClearBackground(this->_backgroundColor);
}

void rl::Window::setBackgroundColor(rl::Color const &color)
{
    this->_backgroundColor = color;
}

rl::Color rl::Window::getBackgroundColor() const
{
    return (this->_backgroundColor);
}

void rl::Window::drawGrid(int slices, float size) const {
    ::DrawGrid(slices, size);
}


// WINDOW GETTERS ----------------------------------------------------------- //

std::string rl::Window::getTitle() const
{
    return (this->_title);
}

int rl::Window::getWidth() const
{
    return (this->_width);
}

int rl::Window::getHeight() const
{
    return (this->_height);
}

// WINDOW SETTERS ----------------------------------------------------------- //

void rl::Window::setTitle(const std::string &title)
{
    if (!this->_isOpen)
        throw rl::Error("Window is not open, could not set title", "Window::setTitle");
    this->_title = title;
    ::SetWindowTitle(title.c_str());
}

void rl::Window::setWidth(int width)
{
    if (!this->_isOpen)
        throw rl::Error("Window is not open, could not set width", "Window::setWidth");
    this->_width = width;
    ::SetWindowSize(this->_width, this->_height);
}

void rl::Window::setHeight(int height)
{
    if (!this->_isOpen)
        throw rl::Error("Window is not open, could not set height", "Window::setHeight");
    this->_height = height;
    ::SetWindowSize(this->_width, this->_height);
}

void rl::Window::setSize(int height, int width)
{
    if (!this->_isOpen)
        throw rl::Error("Window is not open, could not set size", "Window::setSize");
    this->_width = width;
    this->_height = height;
    ::SetWindowSize(this->_width, this->_height);
}


// WINDOW MANAGEMENT ------------------------------------------------ //
bool rl::Window::isFullscreen(void)
{
    return (::IsWindowFullscreen());
}
bool rl::Window::isHidden(void)
{
    return (::IsWindowHidden());
}
bool rl::Window::isMinimized(void)
{
    return (::IsWindowMinimized());
}
bool rl::Window::isMaximized(void)
{
    return (::IsWindowMaximized());
}

bool rl::Window::isFocused(void)
{
    return (::IsWindowFocused());
}
bool rl::Window::isResized(void)
{
    return (::IsWindowResized());
}
bool rl::Window::isState(unsigned int flag)
{
    return (::IsWindowState(flag));
}
void rl::Window::setState(unsigned int flags)
{
    ::SetWindowState(flags);
}

void rl::Window::clearState(unsigned int flags)
{
    ::ClearWindowState(flags);
}

void rl::Window::toggleFullscreen(void)
{
    ::ToggleFullscreen();
}

void rl::Window::maximize(void)
{
    ::MaximizeWindow();
}


void rl::Window::minimize(void)
{
    ::MinimizeWindow();
}

void rl::Window::restore(void)
{
    ::RestoreWindow();
}

void rl::Window::setIcon(Image image)
{
    ::SetWindowIcon(image);
}

void rl::Window::setMonitor(int monitor)
{
    ::SetWindowMonitor(monitor);
}

void rl::Window::setMinSize(int width, int height)
{
    ::SetWindowMinSize(width, height);
}

void *rl::Window::getHandle(void) const
{
    return (::GetWindowHandle());
}

rl::Vector2 rl::Window::getPosition(void) const
{
    return (rl::Vector2(::GetWindowPosition()));
}

rl::Vector2 rl::Window::getScaleDPI(void) const
{
    return (rl::Vector2(::GetWindowScaleDPI()));
}

bool rl::Window::isSoundPlaying(Sound sound) const
{
    return (::IsSoundPlaying(sound));
}

// WINDOW DRAWING ----------------------------------------------------------- //

void rl::Window::beginDrawing() const
{
    if (!this->_isOpen)
        throw rl::Error("Window is not open, could not begin drawing", "Window::beginDrawing");
    ::BeginDrawing();
}

void rl::Window::endDrawing() const
{
    if (!this->_isOpen)
        throw rl::Error("Window is not open, could not end drawing", "Window::endDrawing");
    ::EndDrawing();
}

void rl::Window::beginMode2D() const
{
    if (!this->_isOpen)
        throw rl::Error("Window is not open, could not begin mode 2D", "Window::beginMode2D");
    ::BeginMode2D(this->_camera2D);
}

void rl::Window::endMode2D() const
{
    if (!this->_isOpen)
        throw rl::Error("Window is not open, could not end mode 2D", "Window::endMode2D");
    ::EndMode2D();
}

void rl::Window::beginMode3D() const
{
    if (!this->_isOpen)
        throw rl::Error("Window is not open, could not begin mode 3D", "Window::beginMode3D");
    ::BeginMode3D(this->_camera3D);
}

void rl::Window::endMode3D() const
{
    if (!this->_isOpen)
        throw rl::Error("Window is not open, could not end mode 3D", "Window::endMode3D");
    ::EndMode3D();
}

void rl::Window::beginTextureMode(RenderTexture2D const &texture) const
{
    if (!this->_isOpen)
        throw rl::Error("Window is not open, could not begin texture mode", "Window::beginTextureMode");
    ::BeginTextureMode(texture);
}

void rl::Window::endTextureMode() const
{
    if (!this->_isOpen)
        throw rl::Error("Window is not open, could not end texture mode", "Window::endTextureMode");
    ::EndTextureMode();
}

void rl::Window::beginShaderMode(Shader const &shader) const
{
    if (!this->_isOpen)
        throw rl::Error("Window is not open, could not begin shader mode", "Window::beginShaderMode");
    ::BeginShaderMode(shader);
}

void rl::Window::endShaderMode() const
{
    if (!this->_isOpen)
        throw rl::Error("Window is not open, could not end shader mode", "Window::endShaderMode");
    ::EndShaderMode();
}

void rl::Window::beginBlendMode(int mode)
{
    if (!this->_isOpen)
        throw rl::Error("Window is not open, could not begin blend mode", "Window::beginBlendMode");
    ::BeginBlendMode(mode);
}

void rl::Window::endBlendMode(void)
{
    if (!this->_isOpen)
        throw rl::Error("Window is not open, could not end blend mode", "Window::endBlendMode");
    ::EndBlendMode();
}

void rl::Window::beginScissorMode(int x, int y, int width, int height)
{
    if (!this->_isOpen)
        throw rl::Error("Window is not open, could not begin scissor mode", "Window::beginScissorMode");
    ::BeginScissorMode(x, y, width, height);
}

void rl::Window::endScissorMode(void)
{
    if (!this->_isOpen)
        throw rl::Error("Window is not open, could not end scissor mode", "Window::endScissorMode");
    ::EndScissorMode();
}

// WINDOW CURSOR ------------------------------------------------------------ //

void rl::Window::showCursor()
{
    this->_cursor.show();
}

void rl::Window::hideCursor()
{
    this->_cursor.hide();
}

bool rl::Window::isCursorHidden() const
{
    return (this->_cursor.isHidden());
}

void rl::Window::enableCursor()
{
    this->_cursor.enable();
}

void rl::Window::disableCursor()
{
    this->_cursor.disable();
}

bool rl::Window::isCursorOnScreen() const
{
    return (this->_cursor.isOnScreen());
}

bool rl::Window::isCurosrAccessible() const
{
    return (this->_cursor.isAccessible());
}

// WINDOW MOUSE ------------------------------------------------------------- //

rl::Ray rl::Window::getMouseRay() {
    return (rl::Mouse::getRay(this->_camera3D));
}

rl::Vector2 rl::Window::getMousePosition() {
    return (rl::Mouse::getPosition());
}

// WINDOW FPS --------------------------------------------------------------- //

void rl::Window::setTargetFPS(int fps)
{
    this->_fps.setTargetFPS(fps);
}

int rl::Window::getTargetFPS()
{
    return (this->_fps.getTargetFPS());
}

float rl::Window::getFrameTime()
{
    return (this->_fps.getFrameTime());
}

double rl::Window::getTime()
{
    return (this->_fps.getTime());
}

void rl::Window::drawFPS() const
{
    this->_fps.draw();
}

// WINDOW CAMERA ------------------------------------------------------------ //

void rl::Window::updateCamera() {
    this->_camera3D.update();
}

void rl::Window::setCameraMode(rl::CameraMode mode) {
    this->_camera3D.setMode(mode);
}
