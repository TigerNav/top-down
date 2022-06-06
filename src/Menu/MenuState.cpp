#include "MenuState.h"


MenuState::MenuState() {
	switchMenu = false;
}
void MenuState::PollEvents() {

}
void MenuState::Update() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		switchMenu = true;
		
}
void MenuState::render() {
	
}