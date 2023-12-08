#pragma once
#include <iostream>
#include <string>

namespace InkEngine {
	
	class Application;
	class Entity;
	

	class AComponent
	{

	protected : 
		std::string _id;
		Application* app;
		Entity* MyEnt;
	public:

		AComponent();
		virtual void Awake();
		virtual void Start();


		virtual void Update(float deltaTime);
		virtual void LateUpdate(float deltaTime);

		std::string GetID();
		std::string SetID(int i);
	};
}

