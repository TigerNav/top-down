#include "Player.h"
#include <iostream>
#include "../../Utils/Globals.h"
#include "../../Utils/Assets.h"

Player::Player()
{
}

void Player::Playerinit()
{
	if (!texture.loadFromFile(Assets::Player))
		std::cout << "cant load texture" << std::endl;
	sprite.setTexture(texture);
	sprite.setScale(5, 5);
	sprite.setPosition(1600 / 2 - 50, 800 / 2 - 50);
	PlayerCamera.setCenter(sprite.getPosition().x, sprite.getPosition().y);
	PlayerCamera.setSize(1600, 800);

	acceleration = 300;

	animation.AnimationInitilize(&texture, sf::Vector2u(4, 4), 0.2f);
}

void Player::Update(float deltaTime)
{
	globals.PlayerCoords = sprite.getPosition();

	bool isUp = false, isDown = false, isRight = false, isLeft = false;

	speedX = 0;
	speedY = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		speedY += acceleration * deltaTime;
		cameraY += acceleration * deltaTime;
		isDown = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		speedY -= acceleration * deltaTime;
		cameraY -= acceleration * deltaTime;
		isUp = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		speedX += acceleration * deltaTime;
		cameraX += acceleration * deltaTime;
		isRight = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		speedX -= acceleration * deltaTime;
		cameraX -= acceleration * deltaTime;
		isLeft = true;
	}

	sprite.move(speedX, speedY);

	if (isDown)
		animation.Update(0, deltaTime);
	if (isUp)
		animation.Update(3, deltaTime);
	if (isRight)
		animation.Update(2, deltaTime);
	if (isLeft)
		animation.Update(1, deltaTime);

	sprite.setTextureRect(animation.uvRect);
}

void Player::render(sf::RenderWindow *window)
{
	PlayerCamera.move(speedX, speedY);

	window->setView(PlayerCamera);
	window->draw(sprite);
}

sf::Vector2f Player::PlayerCoords()
{
	return sprite.getPosition();
}
sf::View Player::getCamera() {
	return PlayerCamera;
}