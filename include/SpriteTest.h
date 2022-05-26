#include <SFML/Graphics.hpp>

class SpriteTest {

private:

sf::Texture texture;
sf::Sprite  sprite;

public:

void init_sprite();
void update_sprite();
void draw_sprite();
void unload_sprite();


};