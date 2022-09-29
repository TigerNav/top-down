#include "SplashScreen.h"

void SplashScreen::init() {

    if(!texture.loadFromFile(Assets::splashLogo))
        std::cout << "could not load splash logo" << std::endl;
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setPosition(590, 50);

    if(!globals.font.loadFromFile(Assets::menuFont))
        std::cout << "couldn not load font" << std::endl; 
    text.setString("Unknown Game Company");
    text.setFont(globals.font);
    text.setCharacterSize(60);
    text.setStyle(sf::Text::Bold);
    text.setPosition(400, 500);

    textfinish.setString("Done");
    textfinish.setFont(globals.font);
    textfinish.setCharacterSize(60);
    textfinish.setStyle(sf::Text::Bold);
    textfinish.setPosition(650, 700);
    

    playaudioonce = true;
    if(!sb.loadFromFile(Assets::splashSound)) 
        std::cout << "cant find splash audio" << std::endl;
    sound.setBuffer(sb);

    progressOutline.setSize(sf::Vector2f(900,50));
    progressOutline.setOutlineThickness(5);
    progressOutline.setFillColor(sf::Color::Black);
    progressOutline.setOutlineColor(sf::Color::White);
    progressOutline.setPosition(300, 700);
    
    progressBar.setSize(sf::Vector2f(0,50));
    progressBar.setFillColor(sf::Color::Green);
    progressBar.setOutlineThickness(2);
    progressBar.setPosition(300, 700);
    
    fade.setPosition(0,0);
    fade.setFillColor(sf::Color(0,0,0,0));
    fade.setSize(sf::Vector2f(1600, 800));

}

void SplashScreen::update() {

    time = loadingClock.getElapsedTime();


    progressBar.setSize(sf::Vector2f(time.asMilliseconds() / 2,50));


    if(progressBar.getSize().x == 900) {
        if(playaudioonce) {
            sound.play();
            playaudioonce = false;
        }
    } 
    
    

    if(time.asSeconds() >= 3 && i <= 255) {
        i += 0.1;
        fade.setFillColor(sf::Color(0,0,0,i));
    }

}

void SplashScreen::render(sf::RenderWindow *window) {
    window->draw(sprite);
    window->draw(text);
    
    
    if(progressBar.getSize().x <= 900) {
        window->draw(progressOutline);
        window->draw(progressBar);
    } else {
        window->draw(textfinish);
    }

    window->draw(fade);
    

}