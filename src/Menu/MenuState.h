#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Utils/Assets.h"
#include "../Utils/Utils.h"
#include "../Game/GameState.h"
#include "../Utils/Globals.h"
#include "SplashScreen.h"

#define Max_menu_items 3


class MenuState
{

	GameState gameState;
	SplashScreen splashscreen;
	sf::Clock splashClock;
	sf::Time splashTime;
	
	sf::Font font;
	sf::Text mainMenu[Max_menu_items];
	int menuSelections;
	
public:

	bool switchMenu;
	

	MenuState();
	void PollEvents();
	void Update();
	void render(sf::RenderWindow* window);
	void MenuSwitch();
	void MoveUp();
	void MoveDown();

};

