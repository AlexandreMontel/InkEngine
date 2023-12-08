#pragma once
#include "AComponent.h"
#include "box2d/box2d.h"
#include "CollisionListener.h"
#include "Entity.h"

namespace InkEngine{
	class Application;
	class Physics
	{
	protected:
		Application* app;
		b2Vec2* gravity = new b2Vec2(0.0f,10.0f);
		CollisionListener CollListen;
		
	public:

		b2World* world = new b2World(*gravity);

		Physics();
		void Awake();
		void Update(float deltaTime);

		const void static WorldScale();


	};
}

