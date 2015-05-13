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
#include "Entity.h"

class Ship : public Entity{
public:
    Ship(int x, int y);
    virtual ~Ship();
    void moveTo(int x, int y);
    void move(sf::Vector2f vector);
    void setSpeed(float speed);
    float getSpeed();
    void setMainSprite();
    void setLeftSprite();
    void setRightSprite();
protected:
    sf::Texture textureLeft;
    sf::Texture textureRight;
    float speed;
};

#endif	/* SHIP_H */

