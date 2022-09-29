#include "StartNPC.h"

// TOMMOROW START ON MAKING ANIMATION FOR STILL NPCS BY MAKING A WHOLE NEW ANIMATION FUNC

void StartNPC::init()
{
    if (!NPCTexture.loadFromFile(Assets::Npc1))
        std::cout << "couldent get NPC file" << std::endl;

    NPCSprite.setTexture(NPCTexture);
    NPCSprite.scale(5,5);
}

void StartNPC::update(float deltaTime)
{
    NPCSprite.setPosition(500, 500);

    faceUp = false, faceDown = false, faceLeft = false, faceRight = false;

    if (NPCSprite.getPosition().x >= globals.PlayerCoords.x) faceLeft = true;
    if (NPCSprite.getPosition().y >= globals.PlayerCoords.y) faceUp = true;
    if ((NPCSprite.getPosition().x + getBounds().width) <= globals.PlayerCoords.x) faceRight = true;
    if ((NPCSprite.getPosition().y + getBounds().height) <= globals.PlayerCoords.y) faceDown = true;

    if (faceUp)
        animation.UpdateViaCoords(sf::Vector2u(16, 48), 16, 16);
    if (faceDown)
        animation.UpdateViaCoords(sf::Vector2u(16, 0), 16, 16);
    if (faceLeft)
        animation.UpdateViaCoords(sf::Vector2u(16, 16), 16, 16);
    if (faceRight)
         animation.UpdateViaCoords(sf::Vector2u(16, 32), 16, 16);

    NPCSprite.setTextureRect(animation.uvRect);
}

void StartNPC::render(sf::RenderWindow *window)
{
    window->draw(NPCSprite);
}

sf::Vector2f StartNPC::getPosition()
{
    return NPCSprite.getPosition();
}
sf::FloatRect StartNPC::getBounds()
{
    return NPCSprite.getGlobalBounds();
}