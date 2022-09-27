#pragma once
#include "NPCBase.h"
#include "SFML/Graphics.hpp"
#include "../../Utils/Assets.h"

class StartNPC : public NPCBase{



public:
    
    void init();
    void update(float deltaTime);
    void render(sf::RenderWindow *window);


};