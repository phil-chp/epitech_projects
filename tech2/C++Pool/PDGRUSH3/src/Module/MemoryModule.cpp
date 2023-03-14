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

#include "MemoryModule.hpp"

MemoryModule::~MemoryModule()
{
    // do nothing
}

MemoryModule::MemoryModule()
{
    Memory *mem = new Memory;
    std::map<std::string, int> data = getData();

    mem->memTotal   = static_cast<float>(data["MemTotal"]);
    mem->memFree    = static_cast<float>(data["MemAvailable"]);
    mem->swapTotal  = static_cast<float>(data["SwapTotal"]);
    mem->swapFree   = static_cast<float>(data["SwapFree"]);
    mem->active     = static_cast<float>(data["Active"]);
    mem->inactive   = static_cast<float>(data["Inactive"]);
    mem->memUsed    = ((mem->memTotal - mem->memFree) * 100) / mem->memTotal;
    mem->swapUsed   = (mem->swapTotal - mem->swapFree) * 100 / mem->swapTotal;
    this->setConfig(mem);

}

void MemoryModule::refresh()
{
    Memory *mem = new Memory;
    std::map<std::string, int>  data = getData();

    mem->memTotal   = static_cast<float>(data["MemTotal"]);
    mem->memFree    = static_cast<float>(data["MemAvailable"]);
    mem->swapTotal  = static_cast<float>(data["SwapTotal"]);
    mem->swapFree   = static_cast<float>(data["SwapFree"]);
    mem->active     = static_cast<float>(data["Active"]);
    mem->inactive   = static_cast<float>(data["Inactive"]);
    mem->memUsed    = ((mem->memTotal - mem->memFree) * 100) / mem->memTotal;
    mem->swapUsed   = (mem->swapTotal - mem->swapFree) * 100 / mem->swapTotal;
    this->setConfig(mem);
}

std::map<std::string, int> MemoryModule::getData() {
    int                         value;
    std::string                 line;
    std::string                 name;
    std::ifstream               inputFile;
    std::map<std::string, int>  data;

    inputFile.open("/proc/meminfo");
    while (std::getline(inputFile, line)) {
        std::stringstream(line) >> name >> value;
        data[name.substr(0, name.length() - 1)] = value;
    }

    return data;
}
