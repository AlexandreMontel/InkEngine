#include "pch.h"
#include "UserInterface.h"
#include "Application.h"
#include "SpriteRenderer.h"
#include "TextRenderer.h"



void InkEngine::UserInterface::Awake()
{
	app = InkEngine::Application::GetInstance();
	
}

void InkEngine::UserInterface::Update(float deltaTime)
{


}

void InkEngine::UserInterface::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	
}

void InkEngine::UserInterface::AddSpriteRenderer(SpriteRenderer* sprt)
{
	_Sprites.push_back(sprt);
}

void InkEngine::UserInterface::AddTextRenderer(TextRenderer* txt)
{

	
}

