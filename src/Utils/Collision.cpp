#include "Collision.h"
#include "../Map/FindMapLayer.h"


bool Collision::WaterCollision(sf::Sprite sprite) {

	if (sprite.getGlobalBounds().intersects(findMapLayer.FindObjectLayer("WaterCollision"))) {
		CollideWater = true;
	}
	else
		CollideWater = false;
	
	
	return CollideWater;
}

bool Collision::NormalCollision() {
	return CollideNormal;
}

void Collision::NormalCollisionAffect() {

}
