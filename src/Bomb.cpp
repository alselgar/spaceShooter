#include "Bomb.h"

Bomb::Bomb(int x, int y) {
    if(!yellow.loadFromFile("bomb1.png")) {
        std::cout << "Error loading bomb1 texture" << std::endl;
    }

     if(!red.loadFromFile("bomb2.png")) {
        std::cout << "Error loading bomb2 texture" << std::endl;
    }
    sprite.setTexture(yellow);
    sprite.setPosition(x, y);
}


Bomb::~Bomb() {
}


void Bomb::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}



int Bomb::getX() {
    return sprite.getPosition().x;
}

int Bomb::getY() {
    return sprite.getPosition().y;
}

sf::Vector2f Bomb::getDimensions() {
    sf::FloatRect fr = sprite.getGlobalBounds();
    sf::Vector2f dimensions(fr.width, fr.height);
    return dimensions;
}

sf::FloatRect Bomb::getSpriteGlobalBounds() {
    return sprite.getGlobalBounds();
}

bool Bomb::intersects(Ship &s) {
    return sprite.getGlobalBounds().intersects(s.getSpriteGlobalBounds());
}

bool Bomb::intersects(Bullet &b) {
    return sprite.getGlobalBounds().intersects(b.getCircleShapeGlobalBounds());
}

void Bomb::changeSprite() {
    if(sprite.getTexture() == &yellow)
        sprite.setTexture(red);
    else sprite.setTexture(yellow);
}
