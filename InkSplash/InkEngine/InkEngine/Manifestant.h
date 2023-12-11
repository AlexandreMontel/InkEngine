#pragma once
#include "AComponent.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ICollisionable.h"

namespace InkEngine {
	class Application;
	class Entity;

	class Manifestant : public InkEngine::AComponent, public sf::Drawable, public ICollisionable{

	protected:
		Application* app;
		Entity* entity;
		Entity* crowd;
		
		bool followManif = false;
		bool mustSpawnManifestant = false;

	public:
		
		virtual void BeginCollision(Entity* Other) override;
		
		virtual void EndCollision(Entity* Other) override;

		virtual void Awake() override;

		virtual void Update(float deltaTime) override;

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		
	};


}


