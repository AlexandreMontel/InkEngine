#pragma once
#include <iostream>
#include <box2d/box2d.h>
#include "SpriteRenderer.h"
#include "CamComponent.h"
namespace InkEngine {
	class Application;
	class Entity;
	class RigidBody;

	class ComponentCreator
	{
	protected:
		RigidBody* rBComponent;
		Application* app;
		
	public :
		//ComponentCreator();
		void initClass();
		void CreateRigidbody(Entity* ent, b2BodyType bodyType, float gravityScale);
		void CreateSpriteRenderer(Entity* ent, std::string spriteName, InkEngine::SpriteRenderer::OriginPosition posOrigin);
		void CreateCameraComponent(Entity* ent, InkEngine::CamComponent::CameraType camType, Entity* enToFollo = nullptr);
		void CreateBoxCollider(Entity* ent);
		
		
	};
}
