/*
** EPITECH PROJECT, 2022
** ARCADE
** authored by:
**      Vitali DROUJKO  <vitali.droujko@epitech.eu>
**      Pierre PLASSIO  <pierre.plassio@epitech.eu>
**      Philippe CHEYPE <philippe.cheype@epitech.eu>
** File description:
** Wrapper
*/

#ifndef WRAPPER_HPP_
# define WRAPPER_HPP_

#include <iostream>
#include <string>

#include <memory>

namespace arc
{
    template <typename C, typename D>
    class Wrapper
    {
        public:
            Wrapper() : _config(nullptr), _data(nullptr) {};
            ~Wrapper() {};

            std::shared_ptr<C> getConfig() const
            {
                if (!this->_config) {
                    throw std::runtime_error("Error: config is nullptr");
                }
                return (this->_config);
            };

            std::shared_ptr<D> getData() const
            {
                if (!this->_data) {
                    throw std::runtime_error("Error: data is nullptr");
                }
                return (this->_data);
            };

            void setConfig(std::shared_ptr<C> config)
            {
                this->_config = config;
            };

            void setData(std::shared_ptr<D> data)
            {
                this->_data = data;
            };

        private:
            std::shared_ptr<C> _config;
            std::shared_ptr<D> _data;
    };
}

#endif /*Wrapper_HPP_ */
