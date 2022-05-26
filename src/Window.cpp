#include "Window.h"

void Window::open() {
    window.create(sf::VideoMode(800, 800), "Top-Down game");

    
}

void Window::loop() {

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear();

        

        window.display();
    }

    

}

