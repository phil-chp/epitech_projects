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

#ifndef MEMORY_MODULE_HPP_
# define MEMORY_MODULE_HPP_

#include "Configurable.hpp"
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

typedef struct Memory {
    float memTotal;
    float active;
    float inactive;
    float memFree;
    float swapTotal;
    float swapFree;
    float memUsed;
    float swapUsed;
} Memory;

class MemoryModule : public Configurable<Memory>
{
    public:
        MemoryModule();
        ~MemoryModule();
        void refresh();
        std::map<std::string, int> getData();

};

#endif /* !MEMORY_MODULE_HPP_ */
