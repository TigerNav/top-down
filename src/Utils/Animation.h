#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Animation
{
public:
	Animation();
	~Animation();
	void AnimationInitilize(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	void AnimationInitilizeViaCoords(sf::Texture *texture, sf::Vector2u Starting_Coords, sf::Vector2u Ending_Coords, int size_x, int size_y);
	void Update(int row, float deltaTime);
	void UpdateViaCoords(sf::Vector2u StartingCoords, int width, int height);
	void UpdateIdle(int Column, float deltaTime);

	sf::IntRect uvRect;

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	int size_x, size_y;
	float totalTime;
	float switchTime;
};

