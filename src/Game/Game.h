#pragma once

#include <SFML/Graphics.hpp>
#include "../Menu/MenuState.h"
#include "../Pause/PauseState.h"
#include "../Utils/Globals.h"

class Game
{
public:
	sf::RenderWindow* window;
	
	

	globals Globals;
	MenuState menuState;
	GameState gameState;
	PauseState pauseState;

	Game();
	void run();

};

