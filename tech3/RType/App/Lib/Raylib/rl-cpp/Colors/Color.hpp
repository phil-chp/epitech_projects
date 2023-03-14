/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Color
*/

#ifndef RLCOLOR_HPP_
    #define RLCOLOR_HPP_

    #include "Lib/Raylib/rl-cpp/Raylib-cpp.hpp"
    #include "Lib/Raylib/rl-cpp/Vectors/Vectors.hpp"
    #include "Lib/Raylib/rl-cpp/Error/Error.hpp"
    #include "Utils/Color.hpp"
    #include <iostream>
    #include <sstream>
    #include <utility>
    #include <vector>
    #include <cmath>

namespace rl {
    struct Color : public ::Color {
        Color() : ::Color{0, 0, 0, 0} {};
        explicit Color(::Color const &color) : ::Color{color} {};
        Color(unsigned char const &r, unsigned char const &g, unsigned char const &b, unsigned char const &a) : ::Color{r, g, b, a} {};
        explicit Color(Vector4 const &norm) : ::Color{std::move(::ColorFromNormalized(norm))} {};
        explicit Color(float hue, float saturation, float value)
            : ::Color{std::move(::ColorFromHSV(hue, saturation, value))} {};
        explicit Color(unsigned int hex) : ::Color{std::move(::GetColor(hex))} {};
        explicit Color(std::string const &serial) : ::Color{std::move(getColorFromSerial(serial))} {};
        explicit Color(::game::Color const &color) {
            this->r = color._r;
            this->g = color._g;
            this->b = color._b;
            this->a = color._a;
        };



        void operator=(::Color const &color) {
            this->r = color.r;
            this->g = color.g;
            this->b = color.b;
            this->a = color.a;
        }

        void operator=(rl::Color const &color) {
            this->r = color.r;
            this->g = color.g;
            this->b = color.b;
            this->a = color.a;
        }

        // TODO: Make && = operators for all
        void operator=(::Color &&color) {
            this->r = color.r;
            this->g = color.g;
            this->b = color.b;
            this->a = color.a;
        }

        void operator=(::game::Color const &color) {
            this->r = color._r;
            this->g = color._g;
            this->b = color._b;
            this->a = color._a;
        }



        ~Color() = default;

        //* Custom ---------------------------------------------------------- //

        Color round() const {
            return Color(std::round(this->r), std::round(this->g), std::round(this->b), this->a);
        };
        // Returns a string serialized value for a Color
        std::string serialize() const {
            return std::to_string(this->r) + " " + std::to_string(this->g) + " " + std::to_string(this->b) + " " + std::to_string(this->a);
        }
        // split string at spaces and get int values
        Color getColorFromSerial(std::string const &serial) {
            std::vector<std::string> tokens;
            std::stringstream ss(serial);
            std::string s;

            while (std::getline(ss, s, ' ')) {
                tokens.push_back(s);
            }
            if (tokens.size() != 4) {
                throw rl::Error("Invalid color serialization", "Color::getColorFromSerial");
            }
            return Color(std::stoi(tokens[0]), std::stoi(tokens[1]), std::stoi(tokens[2]), std::stoi(tokens[3]));
        }

        //* Built-in -------------------------------------------------------- //

        // Returns color with alpha applied, alpha goes from 0.0f to 1.0f
        void fade(float alpha);
        // Returns hexadecimal value for a Color
        int toInt() const;
        // Returns Color normalized as float [0..1]
        Vector4 normalize() const;
        // Returns HSV values for a Color, hue [0..360], saturation/value [0..1]
        Vector3 toHSV() const;
        // Returns src alpha-blended into dst color with tint
        void alphaBlend(Color const &src, Color const &tint);

        static float getBrightness(rl::Color const &color)
        {
            return std::sqrt(0.299 * color.r * color.r + 0.587 * color.g * color.g + 0.114 * color.b * color.b);
        }
        // Get Color structure from hexadecimal value
        // Color getColor(unsigned int hexValue) const;

        //* Operators ------------------------------------------------------- //

        // Color operator*(Color const c) {
        //     return { this->r * c.r, this->g * c.g, this->b * c.b, this->a };
        // }
        // Color operator+(Color const c) {
        //     return { this->r + c.r, this->g + c.g, this->b + c.b, this->a };
        // }
        // Color operator-(Color const c) {
        //     return { this->r - c.r, this->g - c.g, this->b - c.b, this->a };
        // }
        // Color operator/(Color const c) {
        //     return { this->r / c.r, this->g / c.g, this->b / c.b, this->a };
        // }

        // void operator*=(Color const c) {
        //     *this = *this * c;
        // }
        // void operator+=(Color const c) {
        //     *this = *this + c;
        // }
        // void operator-=(Color const c) {
        //     *this = *this - c;
        // }
        // void operator/=(Color const c) {
        //     *this = *this / c;
        // }

        void debug() const {
            std::cout << "Color: " << this->r << " " << this->g << " " << this->b << " " << this->a << std::endl;
        }

    };
}
#endif /* !RLCOLOR_HPP_ */
