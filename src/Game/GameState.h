#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Entities/Player.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include "../Map/Map.h"
#include "../Utils/Globals.h"
#include <iostream>
#include <filesystem>
#include "Entities/NPCBase.h"
#include "Entities/StartNPC.h"

class GameState
{
public:

	sf::Clock deltaClock;
	Map map;
	Player player;
	globals Globals;
	StartNPC startnpc;

	std::vector<NPCBase> NPC;

	GameState();
	void PollEvents();
	void Update(float deltaTime);
	void render(sf::RenderWindow *window);
	void collision();
};

