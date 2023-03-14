// /*
// ** EPITECH PROJECT, 2022
// ** RType
// ** File description:
// ** SDLDrawable
// */

// #include "ECS/Components/SDLDrawable.hpp"

// //template<>
// //ecs::SDLDrawable::Drawable()
// //{
// //    this->_drawable = lib::sdl::Sprite();
// //}

// template<>
// void ecs::SDLDrawable::draw(const game::Vector2 &position)
// {
//     game::Vector2 size = _drawable.getSize();
//     game::Vector2 scale = _drawable.getScale();
//     SDL_Rect rect = {(int)position.x, (int)position.y, (int)size.x * scale.x , (int)size.y * scale.y};
//     _drawable.draw(&rect);
// }

// template<>
// void ecs::SDLDrawable::swap(lib::sdl::Sprite sprite)
// {
//     _drawable = sprite;
// }

// template<>
// void ecs::SDLDrawable::setScale(const game::Vector2 &scale)
// {
//     _drawable.setScale(scale);
// }

// template<>
// const game::Vector2 ecs::SDLDrawable::getScale()
// {
//     return (_drawable.getScale());
// }

// template<>
// void ecs::SDLDrawable::setAnimate(const game::Rect &animate)
// {
//     _drawable.setAnimate(animate);
// }


// template<>
// const game::Rect ecs::SDLDrawable::getAnimate()
// {
//     return (_drawable.getAnimate());
// }

// template<>
// void ecs::SDLDrawable::setSize(const game::Vector2 &size)
// {
//     _drawable.setSize(size);
// }

// template<>
// const game::Vector2 ecs::SDLDrawable::getSize()
// {
//     return (_drawable.getSize());
// }
