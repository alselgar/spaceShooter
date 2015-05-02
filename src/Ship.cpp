/*
 * File:   Ship.cpp
 * Author: alex
 *
 * Created on 8 de mayo de 2014, 18:38
 */

#include "Ship.h"

Ship::Ship(int x, int y) {
    if(!textureForward.loadFromFile("playerShip.png")) {
        std::cout << "Error loading ship texture - forward" << std::endl;
    }

     if(!textureLeft.loadFromFile("playerShip_left.png")) {
        std::cout << "Error loading ship - left" << std::endl;
    }

     if(!textureRight.loadFromFile("playerShip_right.png")) {
        std::cout << "Error loading ship - right" << std::endl;
    }
    sprite.setTexture(textureForward);
    sprite.setPosition(x, y);
    speed = 100.0;
}


Ship::~Ship() {
}

void Ship::moveTo(int x, int y) {
    sprite.setPosition(x, y);
}

void Ship::move(sf::Vector2f vector) {
    if(vector.x == 0)
        setForwardSprite();
    if(vector.x < 0)
        setLeftSprite();
    if(vector.x > 0)
        setRightSprite();
    sprite.move(vector.x, vector.y);
}

void Ship::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

void Ship::setSpeed(float speed) {
    this->speed = speed;
}

float Ship::getSpeed() {
    return speed;
}

int Ship::getX() {
    return sprite.getPosition().x;
}

int Ship::getY() {
    return sprite.getPosition().y;
}

sf::Vector2f Ship::getDimensions() {
    sf::FloatRect fr = sprite.getGlobalBounds();
    sf::Vector2f dimensions(fr.width, fr.height);
    return dimensions;
}

sf::FloatRect Ship::getSpriteGlobalBounds() {
    return sprite.getGlobalBounds();
}

bool Ship::intersects(Ship &s) {
    return sprite.getGlobalBounds().intersects(s.getSpriteGlobalBounds());
}

bool Ship::intersects(Bullet &b) {
    return sprite.getGlobalBounds().intersects(b.getCircleShapeGlobalBounds());
}

void Ship::setForwardSprite() {
    sprite.setTexture(textureForward);
}

void Ship::setLeftSprite() {
    sprite.setTexture(textureLeft);
}

void Ship::setRightSprite() {
    sprite.setTexture(textureRight);
}
