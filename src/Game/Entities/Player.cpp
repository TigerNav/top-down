#include "Player.h"
#include <iostream>
#include "../../Utils/Assets.h"

Player::Player() {
	if (!texture.loadFromFile(Assets::Player))
		std::cout << "cant load texture" << std::endl;
	sprite.setTexture(texture);
	sprite.setScale(5 ,5);
	sprite.setPosition(1600 / 2 - 50, 800 / 2 - 50);
	PlayerCamera.setCenter(sprite.getPosition().x, sprite.getPosition().y);
	PlayerCamera.setSize(1600, 800);

	animation.AnimationInitilize(&texture, sf::Vector2u(4, 4), 0.2f);
}
void Player::Update() {

	
	bool isUp = false, isDown = false , isRight = false, isLeft = false;

	speedX = 0;
	speedY = 0;

	if (collision.CollideWater) {
		std::cout << "shit pant" << std::endl;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		speedY += 0.1;
		isDown = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		speedY -= 0.1;
		isUp = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		speedX += 0.1;
		isRight = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		speedX -= 0.1;
		isLeft = true;
	}

	sprite.move(speedX, speedY);
	

	if(isDown)
		animation.Update(0, clock.restart().asSeconds());
	if (isUp)
		animation.Update(3, clock.restart().asSeconds());
	if (isRight)
		animation.Update(2, clock.restart().asSeconds());
	if (isLeft)
		animation.Update(1, clock.restart().asSeconds());
	


	sprite.setTextureRect(animation.uvRect);
}
void Player::render(sf::RenderWindow *window) {
	PlayerCamera.move(speedX, speedY);
	window->setView(PlayerCamera);
	window->draw(sprite);
}