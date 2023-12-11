//#pragma once
//#include "AComponent.h"
//#include <SFML/Graphics.hpp>
//#include <SFML/Graphics/Font.hpp>
//
//namespace InkEngine {
//	class Application;
//
//	class TextRenderer : public InkEngine::AComponent, public sf::Drawable
//	{
//	protected:
//
//		Application* app;
//		sf::Font* usingfont;
//
//	public:
//
//		enum OriginPosition
//		{
//			UpLeft,
//			Up,
//			UpRight,
//			Left,
//			Center,
//			Right,
//			DownLeft,
//			Down,
//			DownRight
//		};
//
//
//		virtual void Awake() override;
//
//		//virtual void Update(float deltaTime) override;
//
//		//virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
//
//		void SetSprite(std::string Sprite);
//
//		std::pair<float, float> GetSize();
//
//		void CenterOrigin(OriginPosition OriginePos);
//		void LoadBaseFont();
//	};
//}
//
