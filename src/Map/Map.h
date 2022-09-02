#pragma once
#include <string>
#include <iostream>
#include <tmx/MapLoader.hpp>
#include "../Utils/Globals.h"
#include "../Utils/Assets.h"
#include <tmx/Log.hpp>
#include <SFML/Graphics.hpp>


class Map
{

public:

		
	tmx::MapLoader Loader;
	std::vector<tmx::MapLayer> layers;
	Map();
	std::vector<sf::FloatRect> waterRect;
	void LoadMap();
	void Update();
	void Render(sf::RenderWindow* render);
	std::vector<sf::FloatRect> getWaterRects();
	
private:
	sf::RenderWindow *window;
	
};

