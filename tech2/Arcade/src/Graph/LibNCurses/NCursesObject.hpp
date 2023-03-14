/*
** EPITECH PROJECT, 2022
** ARCADE
** authored by:
**      Vitali DROUJKO  <vitali.droujko@epitech.eu>
**      Pierre PLASSIO  <pierre.plassio@epitech.eu>
**      Philippe CHEYPE <philippe.cheype@epitech.eu>
** File description:
** SDLObject
*/

#ifndef NCURSESOBJECT_HPP_
# define NCURSESOBJECT_HPP_

# include "Core/Core.hpp"
# include "Shared/Color.hpp"
# include "Shared/Arcade.hpp"
# include "Graph/IGraph.hpp"
# include <SDL2/SDL.h>

namespace arc
{
    namespace graph
    {

        struct MetaObjectNCurses
        {
            std::vector<float> position;
            Color color;
            bool state;
            float rotation;
            short orientation;
            char symbol;
        };

        struct NCursesObject
        {
            public:
                NCursesObject(char key, InfoObject const &info, arc::graph::MetaObjectNCurses metaData)
                {
                    this->meta.position      = {0};
                    this->meta.color         = info.color;
                    this->meta.state         = (metaData.state       ? metaData.state       : false);
                    this->meta.rotation      = (metaData.rotation    ? metaData.rotation    : 0.0f);
                    this->meta.orientation   = (metaData.orientation ? metaData.orientation : (short)0);
                    this->meta.symbol        = (metaData.symbol      ? metaData.symbol      : key);

                }

            MetaObjectNCurses meta;
        };
    }
}

#endif /* !NCURSESOBJECT_HPP_ */
