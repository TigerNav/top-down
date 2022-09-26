#pragma once
#include <SFML/Graphics.hpp>
#include "../../Utils/Animation.h"
#include "../../Utils/Globals.h"

class Player
{
private:
	
public:
	float speedX;
	float speedY;
	float cameraX;
	float cameraY;
	float acceleration;
	globals Globals;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Clock clock;
	sf::View PlayerCamera;
	Animation animation;
	Animation IdleAnimation;

	
	void Playerinit();
	void Update(float deltaTime);
	void render(sf::RenderWindow *window);
	
};

