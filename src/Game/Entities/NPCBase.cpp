#include "NPCBase.h"
void NPCBase::setTexture(std::string path) {
    if(!NPCTexture.loadFromFile(path)) 
        std::cout << "couldent get NPC file" << std::endl;

    NPCSprite.setTexture(NPCTexture);
    animation.AnimationInitilize(&NPCTexture, sf::Vector2u(0, 4), 0);
}

void NPCBase::setPosition(float X, float Y) {
    NPCSprite.setPosition(X, Y);
}

void NPCBase::animate(float deltaTime) {
    


    if(faceUp)
        animation.Update(3, deltaTime);
    if(faceDown)
        animation.Update(0, deltaTime);
    if(faceLeft)
        animation.Update(1, deltaTime);
    if(faceRight)
        animation.Update(2, deltaTime);

    NPCSprite.setTextureRect(animation.uvRect);


}

void NPCBase::talk(std::string talk) {

}