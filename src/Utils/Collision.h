#pragma once

#include <SFML/Graphics.hpp>
#include "../Map/Map.h"
#include "../Map/FindMapLayer.h"

class Collision
{
public:
	
	FindMapLayer findMapLayer;

	bool CollideWater;
	bool CollideNormal;

	bool WaterCollision(sf::Sprite sprite);
	bool NormalCollision();
	void NormalCollisionAffect();
};

