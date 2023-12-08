#include "pch.h"
#include "MovementInput.h"
#include "Application.h"
#include "Entity.h"
#include <iostream>

void InkEngine::MovementInput::Awake()
{
	app = InkEngine::Application::GetInstance();
	MyEnt = app->GetMyEntity(this);

}

void InkEngine::MovementInput::Update(float deltaTime)
{
	MyEnt->setPosition(Move().x, Move().y);
}

sf::Vector2i InkEngine::MovementInput::Move()
{

	sf::Vector2i mousePos = sf::Mouse::getPosition(app->_windows);
	mousePos.x = mousePos.x - app->_windows.getSize().x/2;
	mousePos.y = mousePos.y - app->_windows.getSize().y/2;

	//std::cout << "(" + std::to_string(mousePos.x) + ";" + std::to_string(mousePos.y) + ")" << std::endl;
	
	return mousePos;
}