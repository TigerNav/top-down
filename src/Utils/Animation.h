#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
public:
	Animation();
	~Animation();
	void AnimationInitilize(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	void Update(int row, float deltaTime);
	void UpdateIdle(int Column, float deltaTime);

	sf::IntRect uvRect;

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
};

