#pragma once
#include"AComponent.h"
#include "SFML/Graphics/View.hpp"


namespace InkEngine {

	class Application;
	class Entity;

	class CameraComponent : public InkEngine::AComponent, public sf::View {
	
	protected:
		
		Application* app;
		bool followObject;
		Entity* ObjectToFollow;
			
	public:
		bool cameraPrincipal;
		sf::View cameraView;

		CameraComponent();

		virtual void Awake() override;
		
		virtual void Update(float deltaTime) override;

		void Zoom(float zoomRate);

		void SetViewport(sf::FloatRect CamView);

		void CameraRotation(float rot);

		void SetObjectToFollow(bool isfollow, Entity* EntTofollow);
	};
}
