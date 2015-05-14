#include "Bomb.h"

Bomb::Bomb(int x, int y) : Entity("bombRed.png", x, y) {

     if(!yellow.loadFromFile("bombYellow.png")) {
        std::cout << "Error loading bombYellow texture" << std::endl;
    }
    mainSprite.setTexture(mainTexture);
    mainSprite.setPosition(x, y);
}


Bomb::~Bomb() {
}


void Bomb::changeSprite() {
    if(mainSprite.getTexture() == &mainTexture)
        mainSprite.setTexture(yellow);
    else mainSprite.setTexture(mainTexture);
}
