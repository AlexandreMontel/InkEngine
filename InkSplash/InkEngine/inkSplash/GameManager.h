#pragma once
#include "InkEngine/AComponent.h"



namespace InkEngine {
	class Application;
	class ComponentCreator;
	class GameManager:  public AComponent 
	{
	protected :
		Application* app;
		

	public :

		void NewManifestant();
		void virtual Awake() override;

	
	};
}

