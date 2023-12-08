#include "InkEngine/pch.h"
#include "InkEngine/Application.h"
#include "InkEngine/Application.h"
#include "InkEngine/BoxCollider.h"
#include "InkEngine/Manifestant.h"
//#include <inkSplash/>
#include "Crowd.h"

InkEngine::Crowd::Crowd() {

	jlm = app->GetGlobalEntity("Player");
	_manifestants.push_back(jlm);
	sf::Vector2f* newPos = new sf::Vector2f(0, 0);
	_positions.push_back(newPos);
}

void InkEngine::Crowd::Awake()
{
	app = InkEngine::Application::GetInstance();
	jlm = app->GetGlobalEntity("Player");
	_manifestants.push_back(jlm);
	sf::Vector2f* newPos = new sf::Vector2f(0, 0);
	_positions.push_back(newPos);
}


void InkEngine::Crowd::addManifestant(Entity* ent)
{
	_manifestants.push_back(ent);
	sf::Vector2f* newPos = new sf::Vector2f(0, 0);
	for (sf::Vector2f* pos : _positions) {
		while (newPos->x == pos->x && newPos->y == pos->y) {
			int a = app->GenerateRandomInt()%10;

			if (a > 7.5) {
				newPos->x += 10;
			}
			else if(a > 5){
				newPos->x -= 10;
			}			
			else if (a > 2.5) {
				newPos->y += 10;
			}				
			else{
				newPos->y -= 10;
			}
		}
			//std::cout << std::to_string(newPos->x) + "," + std::to_string(newPos->y) << std::endl;
	}
		_positions.push_back(newPos);
		man_Pos.insert(std::pair<Entity*, sf::Vector2f*>(ent, newPos));
		NewManifestant();
		
}
	

void InkEngine::Crowd::Update(float deltaTime)
{
	for (Entity* ent : _manifestants)
	{
		if (ent != jlm) {
			ent->setPosition(jlm->getPosition() + *man_Pos.find(ent)->second);
		}
	}

}


void  InkEngine::Crowd::NewManifestant() {

	nextManifestant = app->CreateEntity("Manifestant"+std::to_string(_manifestants.size()), "Manifestant");

	app->CompCrea.CreateSpriteRenderer(nextManifestant, "Manifestant2.png", InkEngine::SpriteRenderer::Center);
	app->CreateComponentAndAttachToEntity<InkEngine::BoxCollider>(nextManifestant);
	app->CreateComponentAndAttachToEntity<InkEngine::Manifestant>(nextManifestant);
	app->CompCrea.CreateRigidbody(nextManifestant, b2_kinematicBody, 1);

	int x = app->GenerateRandomInt() % 1866 + 64;
	int y = app->GenerateRandomInt() % 1026 + 64;
	nextManifestant->setPosition(x,y);
}