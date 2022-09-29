/* #include "NPCBase.h"
void NPCBase::setTexture(std::string path) {
    if(!NPCTexture.loadFromFile(path)) 
        std::cout << "couldent get NPC file" << std::endl;

    NPCSprite.setTexture(NPCTexture);
    animation.AnimationInitilize(&NPCTexture, sf::Vector2u(0, 4), 0);
}

void NPCBase::setPosition(float X, float Y) {
   
}

void NPCBase::animate(float deltaTime) {
    


    


}

void NPCBase::talk(std::string talk) {

}

sf::Vector2f NPCBase::getPos() {
    return NPCSprite.getPosition();
}
*/