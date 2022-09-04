#include "Map.h"

Map::Map() : Loader(Assets::mapPath)
{
}

void Map::LoadMap()
{
	Loader.load(Assets::map);

	Loader.updateQuadTree(sf::FloatRect(0.f, 0.f, 1600.f, 800.f));

	layers = Loader.getLayers();

	for (auto &layer : layers)
	{
		if (layer.name == "WaterCollision")
		{
			for (auto &object : layer.objects)
			{
				waterRect.push_back(object.getAABB());
			}
		}

		if(layer.name == "NormalCollision")
		{
			for(auto &object : layer.objects)
			{
				normalRect.push_back(object.getAABB());
			}
		}
	}
}
void Map::Update()
{
	Loader.updateQuadTree(sf::FloatRect(0.f, 0.f, 800.f, 600.f));
}
void Map::Render(sf::RenderWindow *render)
{
	render->draw(Loader);
}
std::vector<sf::FloatRect> Map::getWaterRects()
{
	return waterRect;
}
std::vector<sf::FloatRect> Map::getNormalRects()
{
	return normalRect;
}