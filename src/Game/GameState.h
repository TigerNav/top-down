#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Utils/Globals.h"
#include "Entities/Player.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include "../Map/Map.h"

class GameState
{
public:
	Map map;
	Player player;
	GameState();
	void PollEvents();
	void Update();
	void render(sf::RenderWindow *window);
};

