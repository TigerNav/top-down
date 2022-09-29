#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "../Utils/Globals.h"
#include "../Utils/Assets.h"

class SplashScreen {

sf::Texture texture;
sf::Sprite  sprite;
sf::Text  text;
sf::Text textfinish;
sf::Clock loadingClock;
sf::Clock clock;
sf::Time  time;
sf::Sound sound;
sf::SoundBuffer sb;
sf::RectangleShape progressBar;
sf::RectangleShape progressOutline;
sf::RectangleShape fade;

float i = 0;
bool playaudioonce;

public:
    void init();
    void update();
    void render(sf::RenderWindow *window);

};