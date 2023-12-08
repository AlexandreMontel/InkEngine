#include "pch.h"
#include "RigidBody.h"
#include "Application.h"
#include "Entity.h"
#include "Collider.h"

InkEngine::RigidBody::RigidBody()
{
	
}
void InkEngine::RigidBody::Awake()
{/*
	app = InkEngine::Application::GetInstance();	
	Ent = app->GetMyEntity(this);*/

	Body = app->gamePhysics->world->CreateBody(&bodyDef);
	SetBodyPos();

	CreationOfFixture();

}

void InkEngine::RigidBody::Update(float deltaTime)
{
	SetBodyPos();
}



void InkEngine::RigidBody::SetBodyType(b2BodyType bodyType)
{
	bodyDef.type = bodyType;
}

void InkEngine::RigidBody::SetBodyPos()
{
	b2Pos = new b2Vec2(Ent->getPosition().x, Ent->getPosition().y);
	Body->SetTransform(*b2Pos, Ent->getRotation());
}

void InkEngine::RigidBody::SetLinearVelocity()
{


}

void InkEngine::RigidBody::SetAngularVelocity()
{

}

bool InkEngine::RigidBody::IsDynamic()
{
	if (bodyDef.type == b2_dynamicBody)
		return true;
	else
		return false;
}

void InkEngine::RigidBody::CreationOfFixture()
{

	for (InkEngine::AComponent* composant : Ent->_Components)
	{
		Collider* Coll = dynamic_cast <InkEngine::Collider*>(composant);
		if (Coll)
		{
			Coll->CreateFixture(Body);
		}

	}
}

void InkEngine::RigidBody::GetBodyPos()
{
	Body->GetPosition();
}

void InkEngine::RigidBody::GetBodyRot()
{

}

void InkEngine::RigidBody::GetLinearVelocity()
{
}

void InkEngine::RigidBody::GetAngularVelocity()
{
}

b2Body* InkEngine::RigidBody::GetBody()
{
	return Body;
}

void InkEngine::RigidBody::setGravity(int i)
{
	bodyDef.gravityScale = i;
}

void InkEngine::RigidBody::SetEntityPos()
{
	Ent = app->GetMyEntity(this);
	Ent->setPosition(Body->GetPosition().x, Body->GetPosition().y);
	Ent->setRotation(Body->GetAngle());
}