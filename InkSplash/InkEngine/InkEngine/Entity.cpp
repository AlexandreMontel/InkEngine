#include "pch.h"
#include "Entity.h"
#include "physics.h"
#include <iostream>
#include "SpriteRenderer.h"


InkEngine::Entity::Entity() {

}

void InkEngine::Entity::Awake(){

	for (AComponent* Acomp : _Components) {
		Acomp->Awake();
	}

}

void InkEngine::Entity::Start(){

}

void InkEngine::Entity::Update(float deltaTime){

	for (InkEngine::AComponent* composant : _Components)
	{
		composant->Update(deltaTime);
	}

	/*if (_name == "Player")
	{
		std::cout << _name + "=" + "(" + std::to_string(Transformable::getPosition().x) + ";" + std::to_string(Transformable::getPosition().y) + ")" << std::endl;
	}
	*/
	
}

void InkEngine::Entity::LateUpdate(){

}

/*std::vector<InkEngine::AComponent*> InkEngine::Entity::getLinkedComponents()
{
	return _components;
}

void InkEngine::Entity::addComponent(InkEngine::AComponent* component) 
{
	_components.push_back(component);
	getLinkedComponents();
}
*/
//
//void InkEngine::Entity::draw(){
//
//}


std::string InkEngine::Entity::SetID(int index){
	std::to_string(index);
	return _id;
}

std::string InkEngine::Entity::GetID(){
	//std::cout << _id;
	return _id;
}

std::string InkEngine::Entity::GetName(){
	//std::cout << _name;
	return _name;
}

void InkEngine::Entity::SetTag(std::string tag)
{
	_Tag = tag;
}

std::string InkEngine::Entity::GetTag()
{
	return _Tag;
}


std::string InkEngine::Entity::SetName(std::string name){
	_name = name;
	
	return std::string();
}

std::pair<float, float> InkEngine::Entity::SetEntitySize()
{
	float x, y;

	x = sf::Transformable::getScale().x;
	y = sf::Transformable::getScale().y;

	for (AComponent* comp : _Components)
	{
		InkEngine::SpriteRenderer* sprtRend = dynamic_cast <InkEngine::SpriteRenderer*>(comp);
		if (sprtRend) {
			x = sprtRend->GetSize().first * x;
			y = sprtRend->GetSize().second * y;
		}
	}

	return std::pair<float,float>(x,y);
}

void InkEngine::Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const{

	states.transform.combine(getTransform());
	
	for (AComponent* composant : _Components) {// lister les Comp de cette entité
		sf::Drawable* drawablecomposant = dynamic_cast <sf::Drawable*>(composant);
		if (drawablecomposant)
		{
			target.draw(*drawablecomposant, states);
		}

	}

}






