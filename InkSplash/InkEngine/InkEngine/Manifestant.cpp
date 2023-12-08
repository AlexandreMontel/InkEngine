#include "pch.h"
#include "Entity.h"
#include "Manifestant.h"
#include <windows.h>
#include "inkSplash/Crowd.h"
#include "Application.h"


void InkEngine::Manifestant::Awake()
{
	/*app = InkEngine::Application::GetInstance();
	entity = app->GetMyEntity(this);*/
}

void InkEngine::Manifestant::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	//target.draw(shape, states);

}
void InkEngine::Manifestant::BeginCollision(Entity* Other)
{
	std::string tag = Other->GetTag();

	if (tag == "Manif") {
		Crowd* cC = Other->getAComponent<InkEngine::Crowd>();
		cC->addManifestant(entity);
		entity->SetTag("Manif");
	}
	else if (tag == "Ennemie"){
		
	}
	
}
void InkEngine::Manifestant::EndCollision(Entity* Other)
{
	
}

void InkEngine::Manifestant::Update(float deltaTime) {

	//std::cout << deltaTime << std::endl;
}