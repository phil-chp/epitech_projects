/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** Window
*/

#ifndef WINDOW_HPP_
    #define WINDOW_HPP_

    #include "Lib/Raylib/rl-cpp/Raylib-cpp.hpp"
    #include "Lib/Raylib/rl-cpp/Windows/Cursor/Cursor.hpp"
    #include "Lib/Raylib/rl-cpp/Windows/FPS/FPS.hpp"
    #include "Lib/Raylib/rl-cpp/Windows/Mouse/Mouse.hpp"
    #include "Lib/Raylib/rl-cpp/Windows/Keyboard/Keyboard.hpp"
    #include "Lib/Raylib/rl-cpp/Windows/Gamepad/Gamepad.hpp"
    #include "Lib/Raylib/rl-cpp/Windows/View/View.hpp"
    #include "Lib/Raylib/rl-cpp/Error/Error.hpp"
    #include "Lib/Raylib/rl-cpp/Windows/Camera/Camera3D.hpp"
    #include "Lib/Raylib/rl-cpp/Windows/Camera/Camera2D.hpp"
    #include "Lib/Raylib/rl-cpp/Windows/Camera/CameraModes.hpp"
    #include "Lib/Raylib/rl-cpp/Colors/Colors.hpp"
    #include "Lib/Raylib/rl-cpp/Collisions/Ray/Ray.hpp"
    #include <iostream>
    #include <string>

namespace rl {

    #define DEFAULT_WIDTH   1920
    #define DEFAULT_HEIGHT  1080

    class Window {
        private:
            Window(const std::string &title = "RType", int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT)
                : _title(title)
                , _width(width)
                , _height(height)
                , _isOpen(false)
                , _backgroundColor(RL_BLACK)
                , _cursor()
                , _fps(60)
                , _camera2D()
                , _camera3D()
                , _exitWindow(false)
            {
                this->init();
            }

            Window(Window const&) = delete;
            void operator=(Window const&) = delete;
        public:
            static Window &getInstance() {
                static Window instance;
                return instance;
            }

            // WINDOW MAIN -------------------------------------------------- //

            void init();
            // Close the window
            void close();
            // Sets the window to be closed on next cycle
            void exit();
            // Check if the window is open
            bool isOpen() const;
            // Detect window close button or ESC key
            bool shouldClose();
            // Detect if exit state is true or false
            bool shouldExit();
            // Set background color (framebuffer clear color)
            void clearBackground() const;
            // Set background color (framebuffer clear color)
            void setBackgroundColor(const rl::Color &color);
            // Get background color
            rl::Color getBackgroundColor() const;
            // Draw grid
            void drawGrid(int slices = 25, float size = 1.0f) const;

        // WINDOW MANAGEMENT ------------------------------------------------ //
            // Check if window is currently fullscreen
            bool isFullscreen(void);
            // Check if window is currently hidden (only PLATFORM_DESKTOP)
            bool isHidden(void);
            // Check if window is currently minimized (only PLATFORM_DESKTOP)
            bool isMinimized(void);
            // Check if window is currently maximized (only PLATFORM_DESKTOP)
            bool isMaximized(void);
            // Check if window is currently focused (only PLATFORM_DESKTOP)
            bool isFocused(void);
            // Check if window has been resized last frame
            bool isResized(void);
            // Check if one specific window flag is enabled
            bool isState(unsigned int flag);
            // Set window configuration state using flags
            void setState(unsigned int flags);
            // Clear window configuration state flags
            void clearState(unsigned int flags);
            // Toggle window state: fullscreen/windowed (only PLATFORM_DESKTOP)
            void toggleFullscreen(void);
            // Set window state: maximized, if resizable (only PLATFORM_DESKTOP)
            void maximize(void);
            // Set window state: minimized, if resizable (only PLATFORM_DESKTOP)
            void minimize(void);
            // Set window state: not minimized/maximized (only PLATFORM_DESKTOP)
            void restore(void);
            // Set icon for window (only PLATFORM_DESKTOP)
            void setIcon(Image image);
            // Set monitor for the current window (fullscreen mode)
            void setMonitor(int monitor);
            // Set window minimum dimensions (for FLAG_WINDOW_RESIZABLE)
            void setMinSize(int width, int height);
            // Get native window handle
            void *getHandle(void) const;
            // Get window position XY on monitor
            Vector2 getPosition(void) const;
            // Get window scale DPI factor
            Vector2 getScaleDPI(void) const;
            // check if a specific sounds is playing
            bool isSoundPlaying(Sound sound) const;

        // WINDOW GETTERS ----------------------------------------------- //
            // Get the title of the window
            std::string getTitle() const;
            // Get the width of the window
            int getWidth() const;
            // Get the height of the window
            int getHeight() const;

            // WINDOW SETTERS ----------------------------------------------- //


            // Set the title of the window
            void setTitle(const std::string &title);
            // Set the width of the window
            void setWidth(int width);
            // Set the height of the window
            void setHeight(int height);
            // // Set the size of the window
            void setSize(int width, int height);


            // WINDOW DRAWING ----------------------------------------------- //

            // Setup canvas (framebuffer) to start drawing
            void beginDrawing() const;
            // End canvas drawing and swap buffers (double buffering)
            void endDrawing() const;
            // Begin 2D mode with custom camera (2D)
            void beginMode2D() const;
            // Ends 2D mode with custom camera
            void endMode2D() const;
            // Begin 3D mode with custom camera (3D)
            void beginMode3D() const;
            // Ends 3D mode and returns to default 2D orthographic mode
            void endMode3D() const;
            // Begin drawing to render texture
            void beginTextureMode(const RenderTexture2D &target) const;
            // Ends drawing to render texture
            void endTextureMode() const;
            // Begin custom shader drawing
            void beginShaderMode(Shader const &shader) const
            {
                if (!this->_isOpen)
                    throw rl::Error("Window is not open, could not begin shader mode", "Window::beginShaderMode");
                ::BeginShaderMode(shader);
            }
            // End custom shader drawing (use default shader)
            void endShaderMode() const;
            // Begin blending mode (alpha, additive, multiplied, subtract, custom)
            void beginBlendMode(int mode);
            // End blending mode (reset to default: alpha blending)
            void endBlendMode(void);
            // Begin scissor mode (define screen area for following drawing)
            void beginScissorMode(int x, int y, int width, int height);
            // End scissor mode
            void endScissorMode(void);

            // WINDOW CURSOR ------------------------------------------------ //

            // Shows cursor
            void showCursor();
            // Hides cursor
            void hideCursor();
            // Check if cursor is not visible
            bool isCursorHidden() const;
            // Enables cursor (unlock cursor)
            void enableCursor();
            // Disables cursor (lock cursor)
            void disableCursor();
            // Check if cursor is on the screen
            bool isCursorOnScreen() const;
            // Checks if cursor is visible, on the screen and active
            bool isCurosrAccessible() const;

            // WINDOW MOUSE ------------------------------------------------- //

            // Returns a ray to the mouse position
            Ray getMouseRay();
            // Returns a ray to the mouse position
            Vector2 getMousePosition();

            // WINDOW FPS --------------------------------------------------- //

            // Set target FPS (maximum)
            void setTargetFPS(int fps);
            // Get current FPS
            int getTargetFPS();
            // Get time in seconds for last frame drawn (delta time)
            float getFrameTime();
            // Get elapsed time in seconds since InitWindow()
            double getTime();
            // draws FPS in the screen
            void drawFPS() const;

            // WINDOW CAMERA ------------------------------------------------ //

            void setCameraMode(rl::CameraMode mode);
            void updateCamera3D();
            void setCamera2D(Vector2 const &offset, const rl::Vector2 &position, float rotation, float zoom) {
                _camera2D.set(offset, position, rotation, zoom);
            }
            void setCamera3D(const rl::Vector3 &position, const rl::Vector3 &target, const rl::Vector3 &up, const float fovy, CameraProjection const &projection) {
                _camera3D.set(position, target, up, fovy, projection);
            }

            rl::Camera2D &getCamera2D() {
                return _camera2D;
            }
            rl::Camera3D &getCamera3D() {
                return _camera3D;
            }

            rl::Vector3 getCameraPosition() {
                return _camera3D.getPosition();
            }

        private:

            std::string _title;

            int      _width;
            int      _height;

            bool     _isOpen;
            Color    _backgroundColor;

            Cursor   _cursor;
            FPS      _fps;
            Camera2D _camera2D;
            Camera3D _camera3D;

            bool     _exitWindow;
    };
}

#endif /* !WINDOW_HPP_ */
