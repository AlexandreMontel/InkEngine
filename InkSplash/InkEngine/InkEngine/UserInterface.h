#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include "SFML/Graphics.hpp"
#include "AComponent.h"

namespace InkEngine {
	class Application;
	class Entity;
	class SpriteRenderer;
	class TextRenderer;


	class UserInterface :public AComponent, public sf::Drawable
	{
	protected : 

		std::vector<SpriteRenderer*> _Sprites;
		std::vector< TextRenderer*> _Text;



	public :

		virtual void Awake() override;
		
		virtual void Update(float deltaTime) override;

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		
		void AddSpriteRenderer(SpriteRenderer* sprt);
		void AddTextRenderer(TextRenderer* txt);
	};
}


