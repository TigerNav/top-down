#include "GameState.h"

GameState::GameState()
{
	map.LoadMap();
	player.Playerinit();
	startnpc.init();
}
void GameState::PollEvents()
{
}
void GameState::Update(float deltaTime)
{

	map.Update();
	player.Update(deltaTime);
	startnpc.update(deltaTime);

	globals.playerCamera = player.getCamera();

	collision();
}
void GameState::render(sf::RenderWindow *window)
{
	map.Render(window);
	player.render(window);
	startnpc.render(window);
}

void GameState::collision()
{
	for (auto waterRects : map.getWaterRects())
	{
		if (player.sprite.getGlobalBounds().intersects(waterRects))
		{
		}
	}

	for (auto normalRects : map.getNormalRects())
	{

		if (player.sprite.getGlobalBounds().intersects(normalRects))
		{

			if (normalRects.width >= normalRects.height)
			{

				if (normalRects.contains({normalRects.left, player.sprite.getPosition().y}))
				{
					// Top side crash
					player.PlayerCamera.setCenter(player.sprite.getPosition());
					player.sprite.setPosition(player.sprite.getPosition().x, player.sprite.getPosition().y + 3);
				}
				else
				{
					// bottom side crash
					player.PlayerCamera.setCenter(player.sprite.getPosition());
					player.sprite.setPosition(player.sprite.getPosition().x, player.sprite.getPosition().y - 3);
				}
			}

			if (normalRects.width <= normalRects.height)
			{

				if (normalRects.contains({player.sprite.getPosition().x + player.sprite.getGlobalBounds().width - 1.f, normalRects.top + 1.f}))
				{
					// Right side crash

					player.PlayerCamera.setCenter(player.sprite.getPosition());
					player.sprite.setPosition(player.sprite.getPosition().x - 3, player.sprite.getPosition().y);
				}
				else
				{
					// Left side crash
					player.PlayerCamera.setCenter(player.sprite.getPosition());
					player.sprite.setPosition(player.sprite.getPosition().x + 3, player.sprite.getPosition().y);
				}
			}
		}
	}
}
