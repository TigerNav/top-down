#pragma once

#include <tmx/MapLoader.hpp>

struct globals {

	

	bool InMenu = true;
	bool InGame = false;
	bool InPause = false;

	float deltaTime = 0.0f;
	sf::Clock clock;

	

};