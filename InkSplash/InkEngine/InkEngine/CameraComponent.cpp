#include "pch.h"
#include "CameraComponent.h"

InkEngine::CameraComponent::CameraComponent(){
	
	app = InkEngine::Application::GetInstance();
	
	app->GetInstance();

}


void InkEngine::CameraComponent::Zoom(float zoomRate){

	InkEngine::CameraComponent::cameraView.zoom(zoomRate);
}

void InkEngine::CameraComponent::SetViewport(sf::FloatRect camView){
	

}

void InkEngine::CameraComponent::CameraRotation(float rot)
{
	InkEngine::CameraComponent::cameraView.setRotation(rot);
}

void InkEngine::CameraComponent::Awake()
{
	cameraPrincipal = true;

	Entity* ent = app->GetMyEntity(this);

	cameraView.setCenter(ent->getPosition());
	cameraView.setSize(sf::Vector2f(200.f, 200.f));
	
}

void InkEngine::CameraComponent::SetObjectToFollow(bool isfollow, Entity* EntTofollow = nullptr){

	followObject = isfollow;	
	
	if (followObject)
	{
		ObjectToFollow = EntTofollow;
	}
}

void InkEngine::CameraComponent::Update(float deltaTime)
{
	if (followObject)
	{
		Entity* myEnt = app->GetMyEntity(this);
		myEnt->setPosition(ObjectToFollow -> getPosition());
		cameraView.setCenter(myEnt->getPosition());
		cameraView.setSize(sf::Vector2f(200.f, 200.f));
	}
	if (cameraPrincipal) {

		//app->GetWindow().setView(cameraView);
	
	}
	
}

