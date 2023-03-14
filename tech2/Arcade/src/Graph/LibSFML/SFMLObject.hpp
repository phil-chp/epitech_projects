/*
** EPITECH PROJECT, 2022
** ARCADE
** authored by:
**      Vitali DROUJKO  <vitali.droujko@epitech.eu>
**      Pierre PLASSIO  <pierre.plassio@epitech.eu>
**      Philippe CHEYPE <philippe.cheype@epitech.eu>
** File description:
** SFMLObject
*/

#ifndef SFMLOBJECT_HPP_
# define SFMLOBJECT_HPP_

# include "Core/Core.hpp"
# include "Shared/Color.hpp"
# include "Shared/Arcade.hpp"
# include "Graph/IGraph.hpp"
# include <SFML/Graphics.hpp>
# include <SFML/System.hpp>

namespace arc
{
    namespace graph
    {
        struct MetaObjectSFML
        {
            sf::Color color;
            sf::Sprite sprite;
            sf::Texture *texture;
            int   animate;
            bool  state;
            float rotation;
            short orientation;
            int   width;
            int   height;
        };

        struct SFMLObject {
            public:
                SFMLObject(std::string const &path, sf::RenderWindow *window, arc::graph::MetaObjectSFML metaData)
                {
                    (void) window;
                    this->meta.texture     = (metaData.texture     ? metaData.texture     : nullptr);
                    this->meta.animate     = (metaData.animate     ? metaData.animate     : 0);
                    this->meta.state       = (metaData.state       ? metaData.state       : true);
                    this->meta.rotation    = (metaData.rotation    ? metaData.rotation    : 0.0f);
                    this->meta.orientation = (metaData.orientation ? metaData.orientation : 0);
                    this->meta.width       = (metaData.width       ? metaData.width       : 32);
                    this->meta.height      = (metaData.height      ? metaData.height      : 32);

                    this->meta.texture = new sf::Texture();
                    this->meta.texture->loadFromFile(path);
                    this->meta.sprite.setTextureRect(sf::IntRect(0, 0, this->meta.width, this->meta.height));
                    this->meta.sprite.setTexture(*this->meta.texture);
                    // this->meta.texture = new sf::Texture(this->meta.sprite);
                    // if (!this->meta.texture)
                    //     throw std::runtime_error("could not load texture");
                };

                MetaObjectSFML meta;
        };
    }
}

#endif /* !SFMLOBJECT_HPP_ */
