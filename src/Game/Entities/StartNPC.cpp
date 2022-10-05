#include "StartNPC.h"

void StartNPC::init()
{
    if (!NPCTexture.loadFromFile(Assets::Npc1))
        std::cout << "couldent get NPC file" << std::endl;

    NPCSprite.setTexture(NPCTexture);
    NPCSprite.scale(5, 5);
    textbox.InitTextBox();
    textbox.CharacterSprite(NPCSprite);
    convo[0] ="Press the ENTER button in order to go to ";
    convo[1] ="test 2";
    convo[2] ="test 3";
}

void StartNPC::update(float deltaTime)
{
    NPCSprite.setPosition(500, 500);

    faceUp = false, faceDown = false, faceLeft = false, faceRight = false;

    if (NPCSprite.getPosition().x >= globals.PlayerCoords.x)
        faceLeft = true;
    if (NPCSprite.getPosition().y >= globals.PlayerCoords.y)
        faceUp = true;
    if ((NPCSprite.getPosition().x + getBounds().width) <= globals.PlayerCoords.x)
        faceRight = true;
    if ((NPCSprite.getPosition().y + getBounds().height) <= globals.PlayerCoords.y)
        faceDown = true;

    if (faceUp)
        animation.UpdateViaCoords(sf::Vector2u(16, 48), 16, 16);
    if (faceDown)
        animation.UpdateViaCoords(sf::Vector2u(16, 0), 16, 16);
    if (faceLeft)
        animation.UpdateViaCoords(sf::Vector2u(16, 16), 16, 16);
    if (faceRight)
        animation.UpdateViaCoords(sf::Vector2u(16, 32), 16, 16);

    NPCSprite.setTextureRect(animation.uvRect);
           

    textbox.setUvRect(animation.uvRect);
    textbox.PlayerUI();
    textbox.update(convo);
    textbox.resetText();
    


}

void StartNPC::render(sf::RenderWindow *window)
{
    window->draw(NPCSprite);
    textbox.render(window);
}

sf::Vector2f StartNPC::getPosition()
{
    return NPCSprite.getPosition();
}
sf::FloatRect StartNPC::getBounds()
{
    return NPCSprite.getGlobalBounds();
}