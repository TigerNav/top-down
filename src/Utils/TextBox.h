#include "SFML/Graphics.hpp"
#include "Assets.h"
#include "Globals.h"
#include <cstring>

class TextBox {

private:
    sf::Texture textbox;
    sf::Texture charbox;
    sf::Texture arrowbox;
    sf::Sprite arrowsprite;
    sf::Sprite textsprite;
    sf::Sprite charSprite;
    
    sf::Text text;
    std::string newString;
    sf::Sprite charCopySprite;
    const char* newline = "\n";
    

public:

    unsigned int characters;

    void InitTextBox();
    void CharacterSprite(sf::Sprite charTexture);
    void setUvRect(sf::IntRect uvRect);
    void update(std::string string);
    void resetText();
    void render(sf::RenderWindow *window);


};