#include "pch.h"
#include "CamComponent.h"
#include "Application.h"
#include "Entity.h"
#include "SpriteRenderer.h"

InkEngine::CamComponent::CamComponent(){

	
	}
	


void InkEngine::CamComponent::Awake()
{
	app = InkEngine::Application::GetInstance();
	cameraPrincipal = true;
	//SetObjectToFollow(app->GetGlobalEntity("BackGround"));

	Entity* ent = app->GetMyEntity(this);

	switch(CamType)
	{
	case InkEngine::CamComponent::DynamiCam:

		size.first = 1920;
		size.second = 1080;
		cameraView.setSize(sf::Vector2f(size.first, size.second));

		break;
	case InkEngine::CamComponent::FolloCam:

		size = ObjectToFollow->SetEntitySize();
		//std::cout << std::to_string(ObjectToFollow->SetEntitySize()
		cameraView.setSize(sf::Vector2f(size.first, size.second));

		break;
	case InkEngine::CamComponent::StatiCam:

		size.first = 1920;
		size.second = 1080;
		cameraView.setSize(sf::Vector2f(size.first, size.second));

		break;

	default:
		break;
		
	}

	cameraView.setCenter(ent->getPosition());

}

void InkEngine::CamComponent::Update(float deltaTime)
{
	if (followObject){
		Entity* myEnt = app->GetMyEntity(this);

		sf::Vector2f Pos (ObjectToFollow->getPosition().x + ((cameraView.getSize().x/2)), ObjectToFollow->getPosition().y + ((cameraView.getSize().y / 2)));
		myEnt->setPosition(Pos);

		cameraView.setCenter(myEnt->getPosition());

		// set the cameraSize to the fond
		
		sf::Vector2f ScreenSize(ObjectToFollow->SetEntitySize().first, ObjectToFollow->SetEntitySize().second);
		cameraView.setSize(ScreenSize);
		
		//cameraView.setSize(sf::Vector2f(1920, 1080)); //Faire une fonction pour récupérer la taille du fond
	}
	else
	{
		ScreenSize.x = 1920;
		ScreenSize.y = 1080;
	}
	if (cameraPrincipal) {
		
		app->SetWindowSize(ScreenSize);
		app->setTheView(cameraView);
	}	
}

void InkEngine::CamComponent::Zoom(float zoomRate)
{
	InkEngine::CamComponent::cameraView.zoom(zoomRate);
}

void InkEngine::CamComponent::SetViewport(sf::FloatRect CamView)
{
}

void InkEngine::CamComponent::CameraRotation(float rot)
{
	InkEngine::CamComponent::cameraView.setRotation(rot);
}

void InkEngine::CamComponent::SetObjectToFollow(Entity* EntTofollow = nullptr){

	
	ObjectToFollow = EntTofollow;
		
	

}