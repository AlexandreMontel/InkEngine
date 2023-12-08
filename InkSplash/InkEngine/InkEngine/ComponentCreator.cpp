#include "ComponentCreator.h"
#include "pch.h"
#include "ComponentCreator.h"
#include "Application.h"
#include "RigidBody.h"
#include "SpriteRenderer.h"
#include "CamComponent.h"
#include "BoxCollider.h"


void InkEngine::ComponentCreator::initClass()
{
	app = InkEngine::Application::GetInstance();
}


void InkEngine::ComponentCreator::CreateRigidbody(Entity* ent, b2BodyType bodyType, float gravityScale)
{		
		RigidBody* rBC = app->CreateComponentAndAttachToEntity<InkEngine::RigidBody>(ent);
		
		rBC->SetBodyType(bodyType);

		rBC->setGravity(gravityScale);
}

void InkEngine::ComponentCreator::CreateSpriteRenderer(Entity* ent, std::string spriteName, InkEngine::SpriteRenderer::OriginPosition posOrigin )
{
	SpriteRenderer* sRC = app->CreateComponentAndAttachToEntity<InkEngine::SpriteRenderer>(ent);

	sRC->SetSprite(spriteName);
	sRC->CenterOrigin(posOrigin);
}

void InkEngine::ComponentCreator::CreateCameraComponent(Entity* ent, InkEngine::CamComponent::CameraType camType, Entity* enToFollo)
{
	CamComponent* CamC = app->CreateComponentAndAttachToEntity<InkEngine::CamComponent>(ent);
	CamC->CamType = camType;
	
	if (camType == InkEngine::CamComponent::CameraType::FolloCam)
	{
		CamC->SetObjectToFollow(enToFollo);
	}
}

void InkEngine::ComponentCreator::CreateBoxCollider(Entity* ent)
{
	BoxCollider* BoxColl = app->CreateComponentAndAttachToEntity<InkEngine::BoxCollider>(ent);

	BoxColl = nullptr;



}

