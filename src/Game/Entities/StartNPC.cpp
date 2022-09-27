#include "StartNPC.h"

void StartNPC::init() {
    setTexture(Assets::Npc1);
    setPosition(500,500);
}
void StartNPC::update(float deltaTime) {
    animate(deltaTime);
}
void StartNPC::render(sf::RenderWindow *window) {
    window->draw(NPCSprite);
}