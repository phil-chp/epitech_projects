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

#ifndef CONFIGURABLE_HPP_
# define CONFIGURABLE_HPP_

#include "Errors.hpp"

template <typename T> class Configurable {
    public:
        Configurable() : _config(nullptr) {};
        ~Configurable() {};

        T getConfig() const
        {
            if (!this->_config) {
                throw ConfigError("Call set config before");
            }
            return this->_config;
        };

        void setConfig(T *config)
        {
            this->_config = config;
        };

    private:
        T *_config;
};

#endif /* !CONFIGURABLE_HPP_ */
