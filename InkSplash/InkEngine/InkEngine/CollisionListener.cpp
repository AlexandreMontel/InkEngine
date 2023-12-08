#include "pch.h"
#include "CollisionListener.h"
#include "Application.h"
#include "AComponent.h"
#include "RigidBody.h"
#include "Entity.h"
#include "ICollisionable.h"


void InkEngine::CollisionListener::BeginContact(b2Contact* contact)
{
	InkEngine::Application* app;
	app = InkEngine::Application::GetInstance();

	Entity* MyEnt = NULL;
	Entity* OtherEnt = NULL;
		
/*	for (InkEngine::AComponent* comp : app->_Component)
	{
		InkEngine::RigidBody* rB = dynamic_cast <InkEngine::RigidBody*>(comp);


		if (rB && contact->GetFixtureA()->GetBody() == rB->GetBody())
		{
			MyEnt = app->GetMyEntity(rB);
			for (InkEngine::AComponent* compo : MyEnt->_Components)
			{
				InkEngine::ICollisionable* Ico = dynamic_cast <InkEngine::ICollisionable*> (compo);
				if (Ico) {
					Ico->BeginCollision(NULL);
				}
			}
		}
		else if (rB && contact->GetFixtureB()->GetBody() == rB->GetBody())
		{
			OtherEnt = app->GetMyEntity(rB);
			for (InkEngine::AComponent* compo : OtherEnt->_Components)
			{
				InkEngine::ICollisionable* Ico = dynamic_cast <InkEngine::ICollisionable*> (compo);
				if (Ico) {
					Ico->BeginCollision(NULL);

				}
			}
		}
		
	}
*/


	
	for (InkEngine::AComponent* comp : app->_Component)
	{
		InkEngine::RigidBody* rB = dynamic_cast <InkEngine::RigidBody*>(comp);
		if (rB) {
			if (rB && contact->GetFixtureA()->GetBody() == rB->GetBody())
			{
				MyEnt = app->GetMyEntity(rB);
			}
			else if (rB && contact->GetFixtureB()->GetBody() == rB->GetBody())
			{
				OtherEnt = app->GetMyEntity(rB);
			}			
		}
	}
	if (MyEnt != NULL) {
		for (InkEngine::AComponent* compo : MyEnt->_Components)
		{
			InkEngine::ICollisionable* Ico = dynamic_cast <InkEngine::ICollisionable*> (compo);
			if (Ico) {
				Ico->BeginCollision(OtherEnt);
			}
		}
	}
	if (OtherEnt != NULL) {
		for (InkEngine::AComponent* compo : OtherEnt->_Components)
		{
			InkEngine::ICollisionable* Ico = dynamic_cast <InkEngine::ICollisionable*> (compo);
			if (Ico) {
				Ico->BeginCollision(MyEnt);

			}
		}
	}
	

	//collision set MyRB();

	//collision setmy rB();
}

void InkEngine::CollisionListener::EndContact(b2Contact* contact)
{
		InkEngine::Application* app;
		app = InkEngine::Application::GetInstance();
		Entity* MyEnt = NULL;
		Entity* OtherEnt = NULL;
		
		/*for (InkEngine::AComponent* comp : app->_Component)
		{
			InkEngine::RigidBody* rB = dynamic_cast <InkEngine::RigidBody*>(comp);


			if (rB && contact->GetFixtureA()->GetBody() == rB->GetBody())
			{
				MyEnt = app->GetMyEntity(rB);
				for (InkEngine::AComponent* compo : MyEnt->_Components)
				{
					InkEngine::ICollisionable* Ico = dynamic_cast <InkEngine::ICollisionable*> (compo);
					if (Ico) {
						Ico->EndCollision(NULL);
					}
				}
			}
			else if (rB && contact->GetFixtureB()->GetBody() == rB->GetBody())
			{
				OtherEnt = app->GetMyEntity(rB);
				for (InkEngine::AComponent* compo : OtherEnt->_Components)
				{
					InkEngine::ICollisionable* Ico = dynamic_cast <InkEngine::ICollisionable*> (compo);
					if (Ico) {
						Ico->EndCollision(NULL);

					}
				}
			}

		}*/
		
		for (InkEngine::AComponent* comp : app->_Component)
		{
			InkEngine::RigidBody* rB = dynamic_cast <InkEngine::RigidBody*> (comp);
			if (rB && contact->GetFixtureA()->GetBody() == rB->GetBody())
			{
				MyEnt = app->GetMyEntity(rB);
				
			}
			else if (rB && contact->GetFixtureB()->GetBody() == rB->GetBody())
			{
				OtherEnt = app->GetMyEntity(rB);
			}
		}
		if (MyEnt != NULL) {
			for (InkEngine::AComponent* compo : MyEnt->_Components)
			{
				InkEngine::ICollisionable* Ico = dynamic_cast <InkEngine::ICollisionable*> (compo);
				if (Ico) {
					Ico->EndCollision(OtherEnt);
					//A = true;
				}
			}
		}
		if (OtherEnt != NULL) {
			for (InkEngine::AComponent* compo : OtherEnt->_Components)
			{
				InkEngine::ICollisionable* Ico = dynamic_cast <InkEngine::ICollisionable*> (compo);
				if (Ico) {
					Ico->EndCollision(MyEnt);
					//B = true;
				}
			}
		}
		
}
