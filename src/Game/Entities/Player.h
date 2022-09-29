#pragma once
#include <SFML/Graphics.hpp>
#include "../../Utils/Animation.h"
#include "../../Utils/Globals.h"
#include "StartNPC.h"

class Player
{
private:
	
public:
	float speedX;
	float speedY;
	float cameraX;
	float cameraY;
	float acceleration;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Clock clock;
	sf::View PlayerCamera;
	Animation animation;
	Animation IdleAnimation;

	Player();
	void Playerinit();
	void Update(float deltaTime);
	void render(sf::RenderWindow *window);
	sf::View getCamera();
	sf::Vector2f PlayerCoords();
	
};

