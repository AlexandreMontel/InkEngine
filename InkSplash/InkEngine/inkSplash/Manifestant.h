#pragma once
#include "ICollisionable.h"
#include "AComponent.h"
#include <SFML/Graphics.hpp>


namespace InkEngine {
	class Entity;
	class Application;

	class Manifestant : public InkEngine::AComponent, public ICollisionable {

	protected:

		Application* app;
		Entity* ent;

		bool FollowCrowd = false;

	public:

		virtual 

	};
}

