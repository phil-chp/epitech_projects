/*
** EPITECH PROJECT, 2022
** RType
** File description:
** DrawTextSystem
*/

#ifndef DRAWTEXTSYSTEM_HPP_
    #define DRAWTEXTSYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Components/RLDrawable.hpp"
    #include "ECS/Coordinator.hpp"

namespace ecs {
class DrawTextSystem : public ASystem {
    public:
        DrawTextSystem() = default;
        ~DrawTextSystem() = default;

        void update(::engine::PollEvent &event) const final;
};
}
#endif /* !DRAWTEXTSYSTEM_HPP_ */
