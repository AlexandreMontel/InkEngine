#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "AComponent.h"
#include "CamComponent.h"
#include <iostream>
#include <windows.h>
#include <filesystem>
#include "RessourcesManager.h"
#include "Physics.h"
#include "ComponentCreator.h"

namespace InkEngine {
	class Application
	{

	protected:
		static Application* _instance;
		std::map<std::string, std::string> _linkBetweenComponentAndEntity;
		std::map<std::string, int> RenderingLayer;

	public:

		ComponentCreator CompCrea;

		std::vector<AComponent*> _Component;
		std::vector<Entity*> _Entities;

		sf::RenderWindow _windows;
		Physics* gamePhysics;

		//RessourcesManager rM;
		
		Application();
		~Application();

		void GetRessources(TCHAR a);
		void Init();
		void Loop();
		void setTheView(sf::View view);
		void SetWindowSize(sf::Vector2f V2F);
		int GenerateRandomInt();
		//Create
		Entity* CreateEntity(std::string entityName, std::string tag);
		AComponent* CreateAComponent();

		template<class T>
		T* CreateComponentAndAttachToEntity(Entity* toThis);

		//getters:
		static Application* GetInstance();
		Entity* GetGlobalEntity(std::string Name);
		Entity* GetMyEntity(AComponent* comp);
		sf::RenderWindow* GetWindow();	
		void addRenderingLayer();
		void removeLayer();
	};


	
	template<class T>
	T* Application::CreateComponentAndAttachToEntity(Entity* toThis) {
		T* comp = new T();		

		toThis->_Components.push_back(comp);
		_Component.push_back(comp);

		comp->SetID(_Component.size());

		_linkBetweenComponentAndEntity.insert(std::pair<std::string, std::string>(comp->GetID(), toThis->GetName()));

		return comp;
	}

}

