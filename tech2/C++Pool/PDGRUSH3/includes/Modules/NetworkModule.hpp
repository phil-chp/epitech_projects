/*
** EPITECH PROJECT, 2022
** C POOL, rush-03-myGKrellm
** authored by:
**      Philippe CHEYPE <philippe.cheype@epitech.eu>
**      Vitali DROUJKO <vitali.droujko@epitech.eu>
**      Mateo DEROCHE <mateo.deroche.epitech.eu>
** File description:
** TODO
*/

#ifndef NETWORK_MODULE_HPP_
#define NETWORK_MODULE_HPP_

#include "Configurable.hpp"
#include <cstdint>
#include <ctime>
#include <chrono>
#include <cstddef>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <tuple>

typedef struct Network {
    std::vector<std::tuple<float, float>> *array;
    std::time_t timestamp;
    std::tuple<float, float> last_value;
} Network;

class NetworkModule
        : public Configurable<Network>
{
    public:
        NetworkModule();
        ~NetworkModule();
        void refresh();
        std::tuple<float, float> getInstantaneousData(); // TODO @PC
};

#endif /* !NETWORK_MODULE_HPP_ */
