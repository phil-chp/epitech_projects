/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** GameManager
*/

#include "GameEngine/Managers/GameManager.hpp"
#include "GameEngine/Managers/SoundManager.hpp"
#include "GameEngine/Map/Map.hpp"
#include "GameEngine/Square.hpp"
#include "GameEngine/Spawner.hpp"
#include "GameEngine/Player.hpp"
#include "GameEngine/RType/Bonus/BonusFactory.hpp"
#include "GameEngine/RType/Particles/Propulsion.hpp"
#include "GameEngine/RType/Particles/Shield.hpp"
#include "GameEngine/RType/Shader/WaveShader.hpp"
#include "GameEngine/RType/Shader/ColorShader.hpp"
#include "GameEngine/RType/Shader/LightShader.hpp"
#include "GameEngine/RType/Shader/RainShader.hpp"
#include "GameEngine/RType/Shader/GalaxyShader.hpp"

#include "GameEngine/RType/Shoot/SmallShip.hpp"
#include "GameEngine/Managers/PlayerManager.hpp"

#include "GameEngine/GameEntities.hpp"
#include "GameEngine/LinkerEntities.hpp"
#include "GameEngine/UI.hpp"



#include "GameEngine/RType/Enemy/SpaceShipEnemy.hpp"
#include "GameEngine/RType/Enemy/BrainAlienEnemy.hpp"
#include "GameEngine/RType/Enemy/CyborgBobEnemy.hpp"
#include "GameEngine/RType/Enemy/CyborgDamsEnemy.hpp"
#include "GameEngine/RType/Enemy/CyborgMegakongEnemy.hpp"
#include "GameEngine/RType/Boss/Beric.hpp"
#include "GameEngine/RType/Boss/ContreUno.hpp"
#include "GameEngine/RType/Boss/Feur.hpp"

#include "Lib/Raylib/rl-cpp/Colors/Colors.hpp"
#include "Lib/Raylib/rl-cpp/Shaders/Shaders.hpp"



// INIT ------------------------------------------------------------------------

// std::array<bool, 4> _players = {false, true, true, true};
// rl::Vector2 const &screenSize = {
//     float(rl::Window::getInstance().getWidth()),
//     float(rl::Window::getInstance().getHeight())
// };

void engine::GameManager::initMenu()
{
    engine::rtype::MenuParallax parallax;
    ecs::Entity playButton = engine::rtype::PlayButton::construct();
    ecs::Entity selector = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
        selector,
        ecs::Selector {
            .selected = playButton
        }
    );
    ecs::Coordinator::getInstance().addComponent(
        selector,
        ecs::Control {
            .eventID = 0,
            .secondary = false
        }
    );
    // std::cout << "Menu end" << std::endl;

}

void engine::GameManager::initGame()
{
    engine::LevelManager &lm = engine::LevelManager::getInstance();
    lm.instanciate(0);

    engine::GameEntities &entities = engine::GameEntities::getInstance();
    ecs::Coordinator &coord = ecs::Coordinator::getInstance();

    engine::Shader *textureShader = static_cast<engine::Shader *> (lm.getTextureShaderPtr().get());
    engine::Shader *ambiantShader = static_cast<engine::Shader *> (lm.getAmbiantShaderPtr().get());


    engine::rtype::PlayerManager &players = engine::rtype::PlayerManager::getInstance();

    engine::rtype::RaygunBonus bonus(::game::Vector2(1000, 200));
    engine::rtype::BigShipBonus bonus1(::game::Vector2(1000, 400));
    engine::rtype::SmallShipBonus bonus2(::game::Vector2(1000, 600));
    engine::rtype::ShieldBonus bonus3(::game::Vector2(1000, 800));

    // engine::rtype::GalaxyShader galaxyShader;
    // galaxyShader.addShaderedEntity(bonus3.entity);

    // engine::rtype::BrainAlienEnemy nmi;
    // // engine::rtype::SpaceShipEnemy nmi1;
    // engine::rtype::CyborgBobEnemy nmi2;
    // engine::rtype::CyborgDamsEnemy nmi3;
    // engine::rtype::CyborgMegakongEnemy nmi15;
    // engine::rtype::ContreUno nmi4;
    // engine::rtype::Beric nmi5;
    // engine::rtype::Feur nmi6;


    // ecs::UI ui;
    engine::UI ui;

    textureShader->addShaderedEntity(players.getPlayer(0));
    textureShader->addShaderedEntity(players.getPlayer(1));
    textureShader->addShaderedEntity(players.getPlayer(2));
    textureShader->addShaderedEntity(players.getPlayer(3));


    ambiantShader->addShaderedEntity(players.getPlayer(0));
    ambiantShader->addShaderedEntity(players.getPlayer(1));
    ambiantShader->addShaderedEntity(players.getPlayer(2));
    ambiantShader->addShaderedEntity(players.getPlayer(3));


    // ecs::Entity  entity = coord.createEntity();
    // engine::UI ui;

//    ecs::Entity ent = coord.createEntity();
//    coord.addComponent(
//        ent,
//        ecs::SoundEffect {
//            .loop = false,
//            .repeat = 3,
//            .isPlaying = false,
//            .sound = engine::SoundManager::getInstance().getData(engine::SoundType::SO_BOSS1)
//        }
//    );
}

void engine::GameManager::loopGame(engine::PollEvent &pollEvent)
{
    ecs::Coordinator &coord = ecs::Coordinator::getInstance();
    ::rl::Window &win = ::rl::Window::getInstance();
    engine::rtype::PlayerManager &players = engine::rtype::PlayerManager::getInstance();
    engine::LevelManager::getInstance().runMap(pollEvent.dt);
    engine::Boss *boss = static_cast<engine::Boss *> (engine::LevelManager::getInstance().getBossPtr().get());

    win.clearBackground();
    pollEvent.playerEvents[0] = engine::RLEventHandler::getEvent();

    if ((pollEvent.playerEvents[0].pressed & engine::QUIT) == engine::QUIT) {
        pollEvent.quit = true;
    }
    coord.getSystem(ecs::SPAWN_SYSTEM)->update(pollEvent);

    coord.getSystem(ecs::CONTROL_MOVE_SYSTEM)->update(pollEvent);
    coord.getSystem(ecs::AI_SYSTEM)->update(pollEvent);
    coord.getSystem(ecs::SHOOT_SYSTEM)->update(pollEvent);
    coord.getSystem(ecs::BULLET_SYSTEM)->update(pollEvent);
    coord.getSystem(ecs::SCROLL_SYSTEM)->update(pollEvent);
    coord.getSystem(ecs::TEMPORARY_SYSTEM)->update(pollEvent);
    coord.getSystem(ecs::MOVEMENT_SYSTEM)->update(pollEvent);
    coord.getSystem(ecs::PARALLAX_SYSTEM)->update(pollEvent);
    coord.getSystem(ecs::BOUND_SYSTEM)->update(pollEvent);
    coord.getSystem(ecs::LIFE_SYSTEM)->update(pollEvent);
    coord.getSystem(ecs::SOUND_SYSTEM)->update(pollEvent);
    boss->action(boss);

    if (players.checkLoose()) {
        std::cout << "You loose" << std::endl;
        pollEvent.quit = true;
    }

    win.beginDrawing();
        win.beginMode2D();
            coord.getSystem(ecs::PARALLAX_DRAW_SYSTEM)->update(pollEvent);
            coord.getSystem(ecs::ANIMATE_SYSTEM)->update(pollEvent);
            coord.getSystem(ecs::COLLISION_SYSTEM)->update(pollEvent);
            coord.getSystem(ecs::PARTICLES_SYSTEM)->update(pollEvent);
            coord.getSystem(ecs::DRAW_SYSTEM)->update(pollEvent);
            coord.getSystem(ecs::UI_RENDER_SYSTEM)->update(pollEvent);
        win.endMode2D();
        coord.getSystem(ecs::SHADER_SYSTEM)->update(pollEvent);
        win.beginMode2D();
        win.endMode2D();
    win.endDrawing();
}

// void GameManager::initPause();

// LOOPS -----------------------------------------------------------------------

void engine::GameManager::loopMenu(engine::PollEvent &pollEvent)
{
    ecs::Coordinator &coord = ecs::Coordinator::getInstance();
    ::rl::Window &win = ::rl::Window::getInstance();
    win.clearBackground();

    pollEvent.playerEvents[0] = engine::RLEventHandler::getEvent();
    if (((pollEvent.playerEvents[0].pressed & engine::QUIT) == engine::QUIT) || engine::GameManager::getInstance()._quit == true)  {
        pollEvent.quit = true;
    }
    // ecs::Coordinator::getInstance().getSystem(ecs::CONTROL_MOVE_SYSTEM)->update(pollEvent);
    // ecs::Coordinator::getInstance().getSystem(ecs::MOVEMENT_SYSTEM)->update(pollEvent);
    coord.getSystem(ecs::BUTTON_SYSTEM)->update(pollEvent);
    coord.getSystem(ecs::ANIMATE_SYSTEM)->update(pollEvent);

    // win.clearBackground();
    // pollEvent.playerEvents[0] = engine::RLEventHandler::getEvent();
        // std::cout << "quit" << std::endl;
    coord.getSystem(ecs::SELECTOR_SYSTEM)->update(pollEvent);
    coord.getSystem(ecs::SCROLL_SYSTEM)->update(pollEvent);
    win.beginDrawing();
        win.beginMode2D();
            coord.getSystem(ecs::PARALLAX_DRAW_SYSTEM)->update(pollEvent);
            coord.getSystem(ecs::DRAW_SYSTEM)->update(pollEvent);
            coord.getSystem(ecs::DRAW_TEXT_SYSTEM)->update(pollEvent);
        win.endMode2D();
    win.endDrawing();


}
