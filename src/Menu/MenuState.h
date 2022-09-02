#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Game/GameState.h"
#include "../Utils/Globals.h"



class MenuState
{

	GameState gameState;
	globals Globals;

public:

	bool switchMenu;
	bool switchGame;
	bool switchPause;

	MenuState();
	void PollEvents();
	void Update();
	void render();
};

