#pragma once
#include "AComponent.h"
#include "SFML/Graphics.hpp"

namespace InkEngine {
    class Application;
    class Entity;

    class MovementInput :

        public InkEngine::AComponent {

    protected:

        Application* app;
        Entity* MyEnt;

    public:

        virtual void Awake() override;

        virtual void Update(float deltaTime) override;

        sf::Vector2i Move();

    };

}