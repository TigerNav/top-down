#include "TextBox.h"

void TextBox::InitTextBox()
{

    textbox.loadFromFile(Assets::textBox);
    charbox.loadFromFile(Assets::charBox);
    arrowbox.loadFromFile(Assets::arrowbox);
    textsprite.setTexture(textbox);
    charSprite.setTexture(charbox);
    arrowsprite.setTexture(arrowbox);

    characters = 0;
    text.setCharacterSize(30);
    text.setLetterSpacing(2);
    text.setFont(globals.font);
    textsprite.setScale(7, 5);
    charSprite.setScale(5, 5);
    newline = "\n";
}

void TextBox::CharacterSprite(sf::Sprite charTexture)
{
    charCopySprite = charTexture;
}

void TextBox::setUvRect(sf::IntRect uvRect)
{
    charCopySprite.setTextureRect(uvRect);
}

void TextBox::PlayerUI()
{
    textsprite.setPosition(globals.playerCamera.getCenter().x - 550, globals.playerCamera.getCenter().y + 220);
    charSprite.setPosition(globals.playerCamera.getCenter().x - 750, globals.playerCamera.getCenter().y + 220);
    text.setPosition(textsprite.getPosition().x + 20, globals.playerCamera.getCenter().y + 230);
    charCopySprite.setPosition(globals.playerCamera.getCenter().x - 710, globals.playerCamera.getCenter().y + 250);
    arrowsprite.setPosition(globals.playerCamera.getCenter().x + 680, globals.playerCamera.getCenter().y + 350);
}

void TextBox::update(std::string string)
{
    if (globals.clock.getElapsedTime().asSeconds() > 0.01 && characters < string.length())
    {
        globals.clock.restart();
        characters++;

        if(string.length() >= 60)
            string.insert(60, "\n");
        if(string.length() >= 120)
            string.insert(120, "\n");
        if(string.length() >= 180)
            string.insert(180, "\n");

        newString = string.substr(0, characters);

        text.setString(newString);
    }

    if (string.length() <= characters)
        resetTextbox = true;
}

void TextBox::resetText()
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {
        if (resetTextbox)
        {
            characters = 0;
        }
    }
}

void TextBox::remove() {
    removething = true;
}

void TextBox::show() {
    removething = false;
}

void TextBox::render(sf::RenderWindow *window)
{

    if(!removething) {
        window->draw(charSprite);
        window->draw(textsprite);
        window->draw(charCopySprite);
        window->draw(text);
        window->draw(arrowsprite);
    }
}