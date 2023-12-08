#include "pch.h"
#include "Collider.h"

void InkEngine::Collider::CreateFixture(b2Body* rBBody)
{
	b2FixtureDef.shape = GetColliderShape();
	b2FixtureDef.density = 1;
	
	rBBody->CreateFixture(&b2FixtureDef);
}


void InkEngine::Collider::SetDensity()
{

}

void InkEngine::Collider::SetFriction()
{

}
