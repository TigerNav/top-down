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

void TextBox::update(std::string string)
{

    textsprite.setPosition(globals.playerCamera.getCenter().x - 550, globals.playerCamera.getCenter().y + 220);
    charSprite.setPosition(globals.playerCamera.getCenter().x - 750, globals.playerCamera.getCenter().y + 220);
    text.setPosition(textsprite.getPosition().x + 20, globals.playerCamera.getCenter().y + 230);
    charCopySprite.setPosition(globals.playerCamera.getCenter().x - 710, globals.playerCamera.getCenter().y + 250);
    arrowsprite.setPosition(globals.playerCamera.getCenter().x + 680, globals.playerCamera.getCenter().y + 350);

    if (globals.clock.getElapsedTime().asSeconds() > 0.01 && characters < string.length())
    {
        globals.clock.restart();
        characters++;

        string.insert(60, "\n");
        string.insert(120, "\n");
        string.insert(180, "\n");

        newString = string.substr(0, characters);

        text.setString(newString);
    }
}

void TextBox::resetText()
{
}

void TextBox::render(sf::RenderWindow *window)
{

    window->draw(charSprite);
    window->draw(textsprite);
    window->draw(charCopySprite);
    window->draw(text);
    window->draw(arrowsprite);
}