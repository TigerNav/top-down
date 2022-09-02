#include "GameState.h"

GameState::GameState()
{
	map.LoadMap();
	player.Playerinit();
}
void GameState::PollEvents()
{
}
void GameState::Update()
{

	map.Update();
	player.Update();

	

	for (auto waterRects : map.getWaterRects())
	{
		
		if (player.sprite.getGlobalBounds().intersects(waterRects))
			std::cout << "water collided with" << std::endl;
	}
}
void GameState::render(sf::RenderWindow *window)
{
	map.Render(window);
	player.render(window);
}
