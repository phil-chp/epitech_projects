/*
** EPITECH PROJECT, 2022
** Indie-Studio (Workspace)
** File description:
** Coordinator
*/

#include "Coordinator.hpp"

ecs::Coordinator::Coordinator()
    : _componentManager(std::make_shared<ComponentManager>())
    , _entityManager(std::make_shared<EntityManager>())
    , _systemManager(std::make_shared<SystemManager>())
{
    Signature signature;

    this->_systems.insert(std::make_pair(BOMB_SYSTEM,                  this->registerSystem<ecs::BombSystem>()));
    this->_systems.insert(std::make_pair(BUTTON_RENDER_WIDGET_SYSTEM,  this->registerSystem<ecs::RenderButtonWidgetSystem>()));
    this->_systems.insert(std::make_pair(BUTTON_WIDGET_SYSTEM,         this->registerSystem<ecs::WidgetButtonSystem>()));
    this->_systems.insert(std::make_pair(COLLECTIBLE_SYSTEM,           this->registerSystem<ecs::CollectibleSystem>()));
    this->_systems.insert(std::make_pair(COLLISION_SYSTEM,             this->registerSystem<ecs::CollisionSystem>()));
    this->_systems.insert(std::make_pair(CONTROL_SYSTEM,               this->registerSystem<ecs::ControlSystem>()));
    this->_systems.insert(std::make_pair(LIFE_SYSTEM,                  this->registerSystem<ecs::LifeSystem>()));
    this->_systems.insert(std::make_pair(MOVEMENT_SYSTEM,              this->registerSystem<ecs::MovementSystem>()));
    this->_systems.insert(std::make_pair(PARTICLES_SYSTEM,             this->registerSystem<ecs::ParticlesSystem>()));
    this->_systems.insert(std::make_pair(PART_RENDER_SYSTEM,           this->registerSystem<ecs::PartRenderSystem>()));
    this->_systems.insert(std::make_pair(PHYSICS_SYSTEM,               this->registerSystem<ecs::PhysicsSystem>()));
    this->_systems.insert(std::make_pair(PLAYER_RENDER_WIDGET_SYSTEM,  this->registerSystem<ecs::RenderPlayerWidgetSystem>()));
    this->_systems.insert(std::make_pair(RENDER_TEXTURE_WIDGET_SYSTEM, this->registerSystem<ecs::RenderTextureWidgetSystem>()));
    this->_systems.insert(std::make_pair(PLAYER_WIDGET_SYSTEM,         this->registerSystem<ecs::WidgetPlayerSystem>()));
    this->_systems.insert(std::make_pair(MAP_RENDER_WIDGET_SYSTEM,     this->registerSystem<ecs::RenderMapWidgetSystem>()));
    this->_systems.insert(std::make_pair(MAP_WIDGET_SYSTEM,            this->registerSystem<ecs::WidgetMapSystem>()));
    this->_systems.insert(std::make_pair(RENDER_SYSTEM,                this->registerSystem<ecs::RenderSystem>()));
    this->_systems.insert(std::make_pair(RENDER_MODEL_SYSTEM,          this->registerSystem<ecs::RenderModelSystem>()));
    this->_systems.insert(std::make_pair(SETTINGS_RENDER_SYSTEM,       this->registerSystem<ecs::RenderSettingsSystem>()));
    this->_systems.insert(std::make_pair(SETTINGS_SYSTEM,              this->registerSystem<ecs::WidgetSettingsSystem>()));
    this->_systems.insert(std::make_pair(SPREAD_SYSTEM,                this->registerSystem<ecs::SpreadSystem>()));
    this->_systems.insert(std::make_pair(TEMPORARY_SYSTEM,             this->registerSystem<ecs::TemporarySystem>()));
    this->_systems.insert(std::make_pair(PARALLAX_SYSTEM,              this->registerSystem<ecs::ParallaxSystem>()));
    this->_systems.insert(std::make_pair(PARALLAX_RENDER_SYSTEM,       this->registerSystem<ecs::ParallaxRenderSystem>()));
    this->_systems.insert(std::make_pair(PLAY_SOUND_SYSTEM,            this->registerSystem<ecs::PlaySoundSystem>()));
    this->_systems.insert(std::make_pair(SPAWN_SYSTEM,                 this->registerSystem<ecs::SpawnSystem>()));
    this->_systems.insert(std::make_pair(DESTROY_SYSTEM,               this->registerSystem<ecs::DestroySystem>()));
    this->_systems.insert(std::make_pair(TEXTURED_ITEM_SYSTEM,         this->registerSystem<ecs::TexturedItemSystem>()));
    this->_systems.insert(std::make_pair(ANIMATION_SYSTEM,             this->registerSystem<ecs::AnimationSystem>()));

    this->registerComponent<ecs::Alive>();
    this->registerComponent<ecs::Bomb>();
    this->registerComponent<ecs::ButtonWidget>();
    this->registerComponent<ecs::Controlled>();
    this->registerComponent<ecs::Damage>();
    this->registerComponent<ecs::Drawable>();
    this->registerComponent<ecs::DrawableModel>();
    this->registerComponent<ecs::DrawableButtonWidget>();
    this->registerComponent<ecs::DrawablePlayerWidget>();
    this->registerComponent<ecs::DrawableSettingsControl>();
    this->registerComponent<ecs::DrawableMapWidget>();
    this->registerComponent<ecs::Gravity>();
    this->registerComponent<ecs::Item>();
    this->registerComponent<ecs::Particles>();
    this->registerComponent<ecs::PlayerWidget>();
    this->registerComponent<ecs::MapWidget>();
    this->registerComponent<ecs::RigidBody>();
    this->registerComponent<ecs::Scalable>();
    this->registerComponent<ecs::Spread>();
    this->registerComponent<ecs::SoundEffect>();
    this->registerComponent<ecs::ControlWidget>();
    this->registerComponent<ecs::TextureWidget>();
    this->registerComponent<ecs::Temporary>();
    this->registerComponent<ecs::Transform2D>();
    this->registerComponent<ecs::Transform3D>();
    this->registerComponent<ecs::Parallax>();

    this->registerComponent<ecs::PlayerStat>();
    this->registerComponent<ecs::Spawn>();

    signature.set(this->getComponentType<Gravity>());
    signature.set(this->getComponentType<RigidBody>());
    signature.set(this->getComponentType<Transform3D>());
    this->setSystemSignature<PhysicsSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<Transform3D>());
    signature.set(this->getComponentType<Drawable>());
    this->setSystemSignature<RenderSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<Transform3D>());
    signature.set(this->getComponentType<DrawableModel>());
    this->setSystemSignature<RenderModelSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<Bomb>());
    signature.set(this->getComponentType<Transform3D>());
    signature.set(this->getComponentType<Temporary>());
    signature.set(this->getComponentType<Alive>());
    this->setSystemSignature<BombSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<Temporary>());
    this->setSystemSignature<TemporarySystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<RigidBody>());
    signature.set(this->getComponentType<Transform3D>());
    this->setSystemSignature<MovementSystem>(signature);
    this->setSystemSignature<CollisionSystem>(signature);

    signature.set(this->getComponentType<Controlled>());
    this->setSystemSignature<ControlSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<Item>());
    this->setSystemSignature<CollectibleSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<Alive>());
    this->setSystemSignature<LifeSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<Spread>());
    this->setSystemSignature<SpreadSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<ecs::PlayerWidget>());
    signature.set(this->getComponentType<ecs::Transform2D>());
    this->setSystemSignature<ecs::WidgetPlayerSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<ecs::MapWidget>());
    signature.set(this->getComponentType<ecs::Transform2D>());
    signature.set(this->getComponentType<ecs::DrawableMapWidget>());
    this->setSystemSignature<ecs::RenderMapWidgetSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<ecs::MapWidget>());
    signature.set(this->getComponentType<ecs::Transform2D>());
    this->setSystemSignature<ecs::WidgetMapSystem>(signature);
//13
    signature.reset();
    signature.set(this->getComponentType<ecs::ButtonWidget>());
    signature.set(this->getComponentType<ecs::DrawableButtonWidget>());
    signature.set(this->getComponentType<ecs::Transform2D>());
    this->setSystemSignature<ecs::WidgetButtonSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<ecs::PlayerWidget>());
    signature.set(this->getComponentType<ecs::Transform2D>());
    signature.set(this->getComponentType<ecs::DrawablePlayerWidget>());
    this->setSystemSignature<ecs::RenderPlayerWidgetSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<ecs::ButtonWidget>());
    signature.set(this->getComponentType<ecs::Transform2D>());
    signature.set(this->getComponentType<ecs::DrawableButtonWidget>());
    this->setSystemSignature<ecs::RenderButtonWidgetSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<Particles>());
    this->setSystemSignature<ParticlesSystem>(signature);
    this->setSystemSignature<PartRenderSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<ecs::Parallax>());
    this->setSystemSignature<ecs::ParallaxSystem>(signature);
    this->setSystemSignature<ecs::ParallaxRenderSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<ecs::SoundEffect>());
    this->setSystemSignature<ecs::PlaySoundSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<ecs::Transform2D>());
    signature.set(this->getComponentType<ecs::ControlWidget>());
    this->setSystemSignature<ecs::WidgetSettingsSystem>(signature);

    signature.set(this->getComponentType<ecs::DrawableSettingsControl>());
    this->setSystemSignature<ecs::RenderSettingsSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<ecs::Spawn>());
    signature.set(this->getComponentType<ecs::Transform3D>());
    signature.set(this->getComponentType<ecs::Temporary>());
    this->setSystemSignature<ecs::SpawnSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<ecs::Spawn>());
    signature.set(this->getComponentType<ecs::Transform3D>());
    signature.set(this->getComponentType<ecs::Alive>());
    this->setSystemSignature<ecs::DestroySystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<ecs::TextureWidget>());
    this->setSystemSignature<ecs::RenderTextureWidgetSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<ecs::Item>());
    signature.set(this->getComponentType<ecs::DrawableModel>());
    this->setSystemSignature<ecs::TexturedItemSystem>(signature);

    signature.reset();
    signature.set(this->getComponentType<ecs::DrawableModel>());
    signature.set(this->getComponentType<ecs::Controlled>());
    signature.set(this->getComponentType<ecs::Alive>());
    this->setSystemSignature<ecs::AnimationSystem>(signature);
}
