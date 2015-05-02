/*
 * File:   Ship.h
 * Author: alex
 *
 * Created on 8 de mayo de 2014, 18:38
 */

#ifndef SHIP_H
#define	SHIP_H

#include <iostream>
#include "SFML/Graphics.hpp"
#include "Bullet.h"

class Ship {
public:
    Ship(int x, int y);
//    Ship(const Ship& orig);
    virtual ~Ship();
    void draw(sf::RenderWindow &window);
    void moveTo(int x, int y);
    void move(sf::Vector2f vector);
    void setSpeed(float speed);
    float getSpeed();
    int getX();
    int getY();
    sf::Vector2f getDimensions();
    sf::FloatRect getSpriteGlobalBounds();
    bool intersects(Ship &s);
    bool intersects(Bullet &b);
    void setForwardSprite();
    void setLeftSprite();
    void setRightSprite();
protected:
    sf::Texture textureForward, textureLeft, textureRight;
    sf::Sprite sprite;
    float speed;
};

#endif	/* SHIP_H */

