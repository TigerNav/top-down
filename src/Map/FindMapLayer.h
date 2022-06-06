#pragma once
#include "Map.h"
#include <string>
#include <SFML/Graphics.hpp>

class FindMapLayer
{
public:
	
	Map map;
	sf::FloatRect FindObjectLayer(std::string Layer);

};

