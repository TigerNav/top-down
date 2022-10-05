#include "SFML/Graphics.hpp"
#include "Assets.h"
#include "Globals.h"
#include <cstring>
#include <unistd.h>
#include <list>
#include <iterator>

// create a the update function that will take in a array of strings that the character dialogue
// loop throught every single one and once you go onto the next one it deletes the string

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
    std::string stringfromarray;
    sf::Sprite charCopySprite;

    const char* newline = "\n";
    int currentSentence;
    bool removething;
    bool resetbox;


    int i;

public:

    unsigned int characters;

    void InitTextBox();
    void CharacterSprite(sf::Sprite charTexture);
    void setUvRect(sf::IntRect uvRect);
    void PlayerUI();
    void update(std::string convo[]);
    void remove();
    void show();
    void resetText();
    void render(sf::RenderWindow *window);


};