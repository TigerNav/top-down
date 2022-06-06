#include "GameState.h"


GameState::GameState() {
	map.LoadMap();
}
void GameState::PollEvents() {

}
void GameState::Update() {
	player.Update();
	
	map.Update();
}
void GameState::render(sf::RenderWindow *window) {
	map.Render(window);
	player.render(window);
	
}
