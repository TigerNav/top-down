#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entities/Player.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include "../Map/Map.h"
#include "../Utils/Globals.h"
#include <iostream>
#include <filesystem>

class GameState
{
public:

	sf::Clock deltaClock;
	Map map;
	Player player;
	globals Globals;
	

	GameState();
	void PollEvents();
	void Update(float deltaTime);
	void render(sf::RenderWindow *window);
	void collision();
};

