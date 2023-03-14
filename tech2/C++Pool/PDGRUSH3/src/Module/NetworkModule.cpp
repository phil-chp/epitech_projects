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

#include "NetworkModule.hpp"

NetworkModule::~NetworkModule()
{
    // do nothing
}

NetworkModule::NetworkModule()
{
    Network *network = new Network;

    auto time_now = std::chrono::system_clock::now();
    std::time_t time_old = std::chrono::system_clock::to_time_t(time_now);
    network->timestamp = time_old;
    network->last_value = getInstantaneousData();
    network->array = new std::vector<std::tuple<float, float>>;
    this->setConfig(network);
}

void NetworkModule::refresh()
{
    Network *network = new Network;

    auto now = std::chrono::system_clock::now();
    std::time_t time_old = std::chrono::system_clock::to_time_t(now);
    if (time_old - network->timestamp <= 1) return;
    network->timestamp = time_old;
    std::tuple<float, float> newValue = getInstantaneousData();
    std::tuple<float, float> oldValue = network->last_value;
    std::tuple<float, float> diff = std::make_tuple(std::get<0>(newValue) - std::get<0>(oldValue), std::get<1>(newValue) - std::get<1>(oldValue));
    network->last_value = newValue;
    network->array->push_back(diff);
    this->setConfig(network);
}

/* Implementation */

// bool _getNetworkFlow(std::fstream &fs)
// {
//     fs.open("/proc/stat", std::ios::in);
//     if (!fs.is_open()) {
//         std::cerr << "[ERROR] Couldn't fetch CPU stats." << std::endl;
//         return (false);
//     }
//     return (true);
// }

// void _getData(int &up, int &down, std::istringstream)
// {
//     int token;
//
//     for (size_t tokenCount = 0; tokenCount < 9; ++tokenCount) {
//         iss >> token;
//         if (tokenCount == 1) {
//             down += token;
//         } else if (tokenCount == 9) {
            // up += token;
        // }
//     }
// }

std::tuple<float, float> NetworkModule::getInstantaneousData()
{
    // std::tuple<float, float> data;
    // int up = 0;
    // int down = 0;

    // std::fstream fs;
    //  _getNetworkFlow(fs)
    // for (std::string line; std::getline(fs, line); ) {
    //     if (line.compare(0, 2, "wl") == 0 || line.compare(0, 2, "en") == 0) {
    //         std::istringstream iss(line);
                // _getData(up, down, iss);
    //     }
    // }
    // std::cout << "UP: " << up << "\nDOWN: " << down << std::endl;
    // return data;
    return (std::make_tuple(0, 0));
}
