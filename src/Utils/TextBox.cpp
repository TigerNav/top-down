#include "TextBox.h"

void TextBox::InitTextBox()
{

    textbox.loadFromFile(Assets::textBox);
    charbox.loadFromFile(Assets::charBox);
    arrowbox.loadFromFile(Assets::arrowbox);
    textsprite.setTexture(textbox);
    charSprite.setTexture(charbox);
    arrowsprite.setTexture(arrowbox);
    currentSentence = 0;
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

void TextBox::update(std::string convo[])
{

    if (i < 0)
    {
        removething = false;
    }

    if (characters == 0)
    {
        for (int i = this->i; i <= 10; i)
        {
            stringfromarray = convo[i];
            break;
        }
    }

    if (globals.clock.getElapsedTime().asSeconds() > 0.02 && characters < stringfromarray.length())
    {

        globals.clock.restart();
        characters++;

        if (characters == 60)
            stringfromarray.insert(60, "\n");
        if (characters == 120)
            stringfromarray.insert(120, "\n");
        if (characters == 180)
            stringfromarray.insert(180, "\n");

        newString = stringfromarray.substr(0, characters);

        text.setString(newString);
    }

    if (characters >= stringfromarray.length())
    {
        resetbox = true;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && resetbox)
        {
            i++;
            characters = 0;
            resetbox = false;
        }
    }

    if (i > 7)
    {
        removething = true;
    }
}

void TextBox::resetText()
{
}

void TextBox::render(sf::RenderWindow *window)
{

    if (!removething)
    {
        window->draw(charSprite);
        window->draw(textsprite);
        window->draw(charCopySprite);
        window->draw(text);
        if (resetbox)
            window->draw(arrowsprite);
    }
}