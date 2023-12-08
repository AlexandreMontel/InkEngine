#pragma once
#include "InkEngine/AComponent.h"
#include <SFML/Graphics.hpp>


namespace InkEngine {
    class Entity;
    class Application;
    class Crowd :
        public AComponent {

    protected:

        Application* app;
        Entity* jlm;
        Entity* nextManifestant;
        std::vector<Entity*> _manifestants;
        std::vector<sf::Vector2f*> _positions;
        std::map<Entity*, sf::Vector2f*> man_Pos;


    public:
        Crowd();
        void addManifestant(Entity* ent);
        void NewManifestant();
        virtual void Awake() override;
        virtual void Update(float deltaTime);

    };
}
