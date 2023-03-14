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

#ifndef SDLOBJECT_HPP_
# define SDLOBJECT_HPP_

# include "Core/Core.hpp"
# include "Shared/Color.hpp"
# include "Shared/Arcade.hpp"
# include "Graph/IGraph.hpp"
# include <SDL2/SDL.h>

namespace arc
{
    namespace graph
    {
        struct MetaObjectSDL
        {
            SDL_Color color;
            SDL_Rect rect;
            SDL_Surface *surface;
            SDL_Texture *texture;
            int   animate;
            bool  state;
            float rotation;
            short orientation;
            int   width;
            int   height;
        };

        struct SDLObject {
            public:
                SDLObject(std::string const &path, SDL_Renderer *renderer, arc::graph::MetaObjectSDL metaData)
                {
                    // this->meta.color = SDL_Color{255, 255, 255, 255};
                    this->meta.rect = metaData.rect;
                    this->meta.surface     = (metaData.surface     ? metaData.surface     : nullptr);
                    this->meta.texture     = (metaData.texture     ? metaData.texture     : nullptr);
                    this->meta.animate     = (metaData.animate     ? metaData.animate     : 0);
                    this->meta.state       = (metaData.state       ? metaData.state       : true);
                    this->meta.rotation    = (metaData.rotation    ? metaData.rotation    : 0.0f);
                    this->meta.orientation = (metaData.orientation ? metaData.orientation : 0);
                    this->meta.width       = (metaData.width       ? metaData.width       : 32);
                    this->meta.height      = (metaData.height      ? metaData.height      : 32);


                    this->meta.surface = SDL_LoadBMP(path.c_str());
                    if (!this->meta.surface)
                        throw std::runtime_error("could not load sprite");
                    this->meta.texture = SDL_CreateTextureFromSurface(renderer, this->meta.surface);
                    if (!this->meta.texture)
                        throw std::runtime_error("could not load texture");
                };
                MetaObjectSDL meta;
        };
    }
}

#endif /* !SDLOBJECT_HPP_ */
