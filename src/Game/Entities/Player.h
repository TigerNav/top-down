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
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Clock clock;
	sf::View PlayerCamera;
	Animation animation;
	Animation IdleAnimation;
	globals Globals;
	

	
	void Playerinit();
	void Update();
	void render(sf::RenderWindow *window);
	
};

