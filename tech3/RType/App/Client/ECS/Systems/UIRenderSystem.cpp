/*
** EPITECH PROJECT, 2022
** RType
** File description:
** UIRenderSystem
*/

#include "ECS/Systems/UIRenderSystem.hpp"
#include "GameEngine/Managers/FontManager.hpp"
#include "Utils/PathBuilder.hpp"

void ecs::UIRenderSystem::update(::engine::PollEvent &event) const {
    for (ecs::Entity const &entity : this->entities) {
        UI &ui = ecs::Coordinator::getInstance().getComponent<UI>(entity);
        for (short int i = 0; i < ui.maxPlayer; ++i) {
            ui.icon.position = ui.playerPos[i] + ui.iconOffset;
            ui.icon.animRect.x = i * (150 * .4);
            ui.icon.drawAnim();

            std::string txt("Player" + std::to_string(i+1));
            ui.txt.setText(txt);
            ui.txt.position = ui.playerPos[i] + ui.nameOffset;
            ui.txt.drawEx(ui.txt.position,15,0, ::rl::Color(255,255,255,255));

            txt = (std::to_string(ui.score[i]) + "pts");
            while(txt.size() < 9) {
                txt.insert(txt.begin(), '0');
            }
            ui.txt.setText(txt);
            ui.txt.position = ui.playerPos[i] + ui.scoreOffset;
            ui.txt.drawEx(ui.txt.position,15,0, ::rl::Color(255,255,255,255));

            ui.heart.position = ui.playerPos[i] + ui.lifeOffset;
            ui.heart.animRect.x = ui.heartAnimFrame * (50 * .6);
            ui.heart.drawAnim();


            txt = ("      x " + std::to_string(ui.life[i]));
            ui.txt.setText(txt);
            ui.txt.position = ui.playerPos[i] + ui.lifeOffset;
            ui.txt.drawEx(ui.txt.position,15,0, ::rl::Color(255,255,255,255));

            if (ui.mainPlayer == i + 1) {
                txt = ("Upgrade: " + std::to_string(ui.weaponId));
                ui.txt.setText(txt);
                ui.txt.position = ui.playerPos[i] + ui.weapOffset;
                ui.txt.drawEx(ui.txt.position,15,0, ::rl::Color(255,255,255,255));
            }
            ui.heartAnimActualDelay -= event.dt;
            if (ui.heartAnimActualDelay <= 0) {
                ui.heartAnimActualDelay = ui.heartAnimDelay;
                ui.heartAnimFrame++;
                if (ui.heartAnimFrame >= 10)
                    ui.heartAnimFrame = 0;
            }
        }
    }
}
