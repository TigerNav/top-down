#pragma once

#include <tmx/MapLoader.hpp>
#include <SFML/Graphics.hpp>

struct globals {

	

	bool InMenu = true;
	bool InGame = false;
	bool InPause = false;

	float deltaTime = 0.0f;
	sf::FloatRect waterRects;
	sf::Clock clock;
	sf::Font font;
	

	

};