#pragma once

#include <tmx/MapLoader.hpp>
#include <SFML/Graphics.hpp>

struct globals
{

	bool InMenu = true;
	bool InGame = false;
	bool InPause = false;

	sf::FloatRect waterRects;
	sf::Font font;
	sf::Event event;
	sf::Vector2f PlayerCoords;
	sf::Clock clock;
	sf::View playerCamera;

} inline globals;