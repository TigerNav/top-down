#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "Game.h"

class Window {

private:
    std::vector RenderList;

public:
    sf::RenderWindow window;

    void open();
    void loop();


};