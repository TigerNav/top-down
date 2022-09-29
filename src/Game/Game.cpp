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

		while (window->pollEvent(globals.event))
		{
			
			if (globals.InMenu) {
				switch (globals.event.type)
				{
				case sf::Event::KeyReleased:
					switch (globals.event.key.code)
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
			if (globals.InGame)
				gameState.PollEvents();
			if (globals.InPause)
				pauseState.PollEvents();
			if (globals.event.type == sf::Event::Closed)
			{
				std::cout << "App closed";
				exit(0);
			}
		}

		window->clear();

		if (globals.InMenu)
		{

			if (menuState.switchMenu)
			{
				globals.InGame = true;
				globals.InMenu = false;
				menuState.switchMenu = false;
			}

			menuState.Update();
			menuState.render(window);
		}
		if (globals.InGame)
		{

			gameState.Update(deltaTime);
			gameState.render(window);
		}
		else if (globals.InPause)
		{
			pauseState.Update();
			pauseState.render();
		}

		window->display();
	}
}