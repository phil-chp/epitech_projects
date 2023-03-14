/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** Noise
*/

# include <iostream>
# include <vector>
# include <cmath>
# include <random>
# include <string>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <bitset>

//TODO: Je vais refactor tout ça dans la semaine.

class Noise {
    public:
        Noise() {};
        ~Noise() {};

        static std::vector<float> GenerateNoiseMap(int width, int height, int seed) {
            (void)seed;
            // generate a random value between 0 and 1
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<> dis(0, 1);

            // create a vector of floats
            std::vector<float> noiseMap;

            // fill the vector with random values
            for (int i = 0; i < width * height; i++)
                noiseMap.push_back(dis(gen));

            // return the vector
            return noiseMap;
        }
};
