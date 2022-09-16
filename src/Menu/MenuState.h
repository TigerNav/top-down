#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Utils/Assets.h"
#include "../Game/GameState.h"
#include "../Utils/Globals.h"
#include "SplashScreen.h"



class MenuState
{

	GameState gameState;
	SplashScreen splashscreen;
	globals Globals;
	sf::Clock splashClock;
	sf::Time splashTime;
	
	sf::Font font;
	sf::Text Start;
	sf::Text Options;
	sf::Text Exit;
	int menuSelections;
	
public:

	bool switchMenu;
	

	MenuState();
	void PollEvents();
	void Update();
	void render(sf::RenderWindow* window);
};

