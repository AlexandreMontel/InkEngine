#pragma once
#include <string>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <vector>
#include "AComponent.h"
#include "SFML/Graphics.hpp"


namespace InkEngine {
	

	class Entity : public sf::Drawable, public sf::Transformable 
	{

	protected :
		std::string _id;
		std::string _name;
		std::string _Tag;
		
	public:

		std::vector<AComponent*> _Components;

		Entity();
		void Awake();
		void Start();
		void Update(float deltaTime);
		void LateUpdate();
		
		//std::vector<AComponent*> getLinkedComponents();
		//void addComponent(AComponent* composant);
		//void draw();


		std::string SetID(int index);
		std::string GetID();

		std::string SetName(std::string name);
		std::string GetName(); 
		
		void SetTag(std::string tag);
		std::string GetTag();

		std::pair<float, float> SetEntitySize();
		
		
		template<typename T>
		inline T* getAComponent()
		{
			for (AComponent* comp : _Components)
			{
				T* Myclass = dynamic_cast<T*>(comp);
				if (Myclass)
				{
					return Myclass;
				}
			}
			return nullptr;
		}
		
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	};
}

