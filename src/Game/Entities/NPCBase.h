#pragma once
#include <iostream>
#include "../../Utils/Animation.h"
#include <SFML/Graphics.hpp>
#include "Player.h"

class NPCBase
{

private:

protected:
    sf::Texture NPCTexture;
    sf::Sprite NPCSprite;
    sf::FloatRect talkBox;
    Animation animation;
    bool alreadyTalked;
    

public:

// make getters and setters for sprite positions

    bool faceUp, faceDown, faceLeft, faceRight;

    virtual void init() = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render(sf::RenderWindow *window) = 0;

    
    void setTexture(std::string path);
    void setPosition(float X, float Y);
    void animate(float deltaTime);
    void talk(std::string text);

};