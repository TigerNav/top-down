#include "Animation.h"

Animation::Animation() {}

void Animation::AnimationInitilize(sf::Texture *texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;

	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);
}


void Animation::UpdateViaCoords(sf::Vector2u StartingCoords, int width, int height)
{
	uvRect.left	= StartingCoords.x;
	uvRect.top  = StartingCoords.y;
	uvRect.width = width;
	uvRect.height = height;
}

void Animation::UpdateIdle(int column, float deltaTime)
{
	currentImage.x = column;
	totalTime += deltaTime;
	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.y++;

		if (currentImage.y >= imageCount.y)
		{
			currentImage.y = 0;
		}
	}
	uvRect.left = currentImage.x * uvRect.width;
	uvRect.top = currentImage.y * uvRect.height;
}

void Animation::Update(int row, float deltaTime)
{
	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;

		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;
		}
	}

	uvRect.left = currentImage.x * uvRect.width;
	uvRect.top = currentImage.y * uvRect.height;
}

Animation::~Animation()
{
}
