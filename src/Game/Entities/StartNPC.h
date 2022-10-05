#pragma once

#include "SFML/Graphics.hpp"
#include "Player.h"
#include "../../Utils/Globals.h"
#include "../../Utils/Assets.h"
#include "../../Utils/Animation.h"
#include "../../Utils/TextBox.h"
#include <list>

class StartNPC {

    sf::Texture NPCTexture;
    sf::Sprite NPCSprite;
    sf::FloatRect talkBox;
    Animation animation;
    TextBox textbox;

    std::string convo[20];


public:
    
    bool faceUp, faceDown, faceLeft, faceRight;
    void init();
    void update(float deltaTime);
    void render(sf::RenderWindow *window);
    sf::Vector2f getPosition();
    sf::FloatRect getBounds();


};