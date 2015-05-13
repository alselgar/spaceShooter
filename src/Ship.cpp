/*
 * File:   Ship.cpp
 * Author: alex
 *
 * Created on 8 de mayo de 2014, 18:38
 */

#include "Ship.h"

Ship::Ship(int x, int y) : Entity("playerShip.png", x, y){
    // main Sprite and Texture already loaded

     if(!textureLeft.loadFromFile("playerShip_left.png")) {
        std::cout << "Error loading ship - left" << std::endl;
    }

     if(!textureRight.loadFromFile("playerShip_right.png")) {
        std::cout << "Error loading ship - right" << std::endl;
    }

    speed = 100.0;
}


Ship::~Ship() {
}

void Ship::moveTo(int x, int y) {
    mainSprite.setPosition(x, y);
}

void Ship::move(sf::Vector2f vector) {
    if(vector.x == 0)
        setMainSprite();
    if(vector.x < 0)
        setLeftSprite();
    if(vector.x > 0)
        setRightSprite();
    mainSprite.move(vector.x, vector.y);
}

void Ship::setSpeed(float speed) {
    this->speed = speed;
}

float Ship::getSpeed() {
    return speed;
}

void Ship::setMainSprite() {
    mainSprite.setTexture(mainTexture);
}

void Ship::setLeftSprite() {
    mainSprite.setTexture(textureLeft);
}

void Ship::setRightSprite() {
    mainSprite.setTexture(textureRight);
}
