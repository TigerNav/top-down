#include "Map.h"
#include <tmx/MapLoader.hpp>


Map::Map() : Loader("/home/navin/programming/top-down/src/Assets/maps") {

}

void Map::LoadMap() {
	Loader.load("shader_example.tmx");
}
void Map::Update() {

}
void Map::Render(sf::RenderWindow* render) {
	render->draw(Loader);
}
