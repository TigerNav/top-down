#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Game::Game()
{
	window = new sf::RenderWindow(sf::VideoMode(1600, 800), "bruh");
}

void Game::run()
{

	while (window->isOpen())
	{
		deltaTime = deltaClock.restart().asSeconds();

		while (window->pollEvent(Globals.event))
		{
			
			if (Globals.InMenu) {
				switch (Globals.event.type)
				{
				case sf::Event::KeyReleased:
					switch (Globals.event.key.code)
					{
					case sf::Keyboard::Up:
						menuState.MoveUp();
						break;
					case sf::Keyboard::Down:
						menuState.MoveDown();
						break;
					case sf::Keyboard::Return:
						menuState.MenuSwitch();
						break;
					default:
						break;
					}
					break;
				default:
					break;
				}	
				menuState.PollEvents();
			}
			if (Globals.InGame)
				gameState.PollEvents();
			if (Globals.InPause)
				pauseState.PollEvents();
			if (Globals.event.type == sf::Event::Closed)
			{
				std::cout << "App closed";
				exit(0);
			}
		}

		window->clear();

		if (Globals.InMenu)
		{

			if (menuState.switchMenu)
			{
				Globals.InGame = true;
				Globals.InMenu = false;
				menuState.switchMenu = false;
			}

			menuState.Update();
			menuState.render(window);
		}
		if (Globals.InGame)
		{

			gameState.Update(deltaTime);
			gameState.render(window);
		}
		else if (Globals.InPause)
		{
			pauseState.Update();
			pauseState.render();
		}

		window->display();
	}
}