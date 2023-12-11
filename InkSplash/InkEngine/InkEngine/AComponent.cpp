#include "pch.h"
#include "AComponent.h"
#include"Application.h"

InkEngine::AComponent::AComponent() {
	
	/*app = InkEngine::Application::GetInstance();
	MyEnt = app->GetMyEntity(this);*/
}

void InkEngine::AComponent::Awake()
{
}

void InkEngine::AComponent::Start()
{
}

void InkEngine::AComponent::Update(float deltaTime)
{
	
}

void InkEngine::AComponent::LateUpdate(float deltaTime)
{
}


std::string InkEngine::AComponent::SetID(int i) {
	_id = std::to_string(i);
	//std::cout << _id << std::endl;
	
	return _id;
}


std::string InkEngine::AComponent::GetID() {
	
	return _id;
}

