#pragma once
#include <string>
#include <tmx/MapLoader.hpp>
#include <SFML/Graphics.hpp>


class Map
{

public:
	tmx::MapLoader Loader;

	Map();
	void LoadMap();
	void Update();
	void Render(sf::RenderWindow* render);
};

