#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Game::Game() {
	window = new sf::RenderWindow(sf::VideoMode(1600, 800), "bruh");
	
}

void Game::run() {

	while (window->isOpen()) {
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				exit(0);
			if (Globals.InMenu) 
				menuState.PollEvents();
			if (Globals.InGame)
				gameState.PollEvents();
			if (Globals.InPause)
				pauseState.PollEvents();
		}

		window->clear();

		if (Globals.InMenu) {
			

			if (menuState.switchMenu) {
				Globals.InGame = true;
				Globals.InMenu = false;
				menuState.switchMenu = false;
			}

			menuState.Update();
			menuState.render();
		}
		if (Globals.InGame) {
			
			gameState.Update();
			gameState.render(window);
		}
		else if (Globals.InPause) {
			pauseState.Update();
			pauseState.render();
		}
			
		window->display();		
	}
}