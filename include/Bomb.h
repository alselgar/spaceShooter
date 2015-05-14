#ifndef BOMB_H
#define BOMB_H

#include "SFML/Graphics.hpp"
#include "Ship.h"
#include "Bullet.h"

class Bomb : public Entity
{
public:
    Bomb(int x, int y);
    virtual ~Bomb();
    void changeSprite();

protected:
    sf::Texture yellow;
};

#endif // BOMB_H
