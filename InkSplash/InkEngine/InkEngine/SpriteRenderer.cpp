#include "pch.h"
#include "SpriteRenderer.h"



void InkEngine::SpriteRenderer::Awake()
{
	
}

void InkEngine::SpriteRenderer::Update(float deltaTime)
{


}


void InkEngine::SpriteRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}

void InkEngine::SpriteRenderer::SetSprite(std::string Sprite)
{
	if (!texture.loadFromFile("img/" + Sprite))
	{
		std::cout << "file not Found" << std::endl;
	}
	sprite.setTexture(texture);
	
}

void InkEngine::SpriteRenderer::CenterOrigin(OriginPosition OriginePos) {

	if (OriginePos == UpLeft)
	{
		sprite.setOrigin(0, 0);
	}
	else if (OriginePos == Up){
		sprite.setOrigin(texture.getSize().x / 2, 0);
	}
	else if (OriginePos == UpRight){
		sprite.setOrigin(texture.getSize().x, 0);
	}
	else if (OriginePos == Left){
		sprite.setOrigin(0, texture.getSize().y / 2);
	}
	else if (OriginePos == Center){
		sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	}
	else if (OriginePos == Right){
		sprite.setOrigin(texture.getSize().x, texture.getSize().y / 2);
	}
	else if (OriginePos == DownLeft){
		sprite.setOrigin(0, texture.getSize().y);
	}
	else if (OriginePos == Down){
		sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y);
	}
	else if (OriginePos == DownRight) {
		sprite.setOrigin(texture.getSize().x, texture.getSize().y);
	}

}



std::pair<float, float> InkEngine::SpriteRenderer::GetSize()
{
	float x, y;
	x = texture.getSize().x;
	y = texture.getSize().y;
	//la position, scale;

	return std::pair<float,float>(x,y);
}

 