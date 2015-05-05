#ifndef BOMB_H
#define BOMB_H

#include "SFML/Graphics.hpp"
#include "Ship.h"
#include "Bullet.h"

class Bomb
{
public:
    Bomb(int x, int y);
    virtual ~Bomb();
    void draw(sf::RenderWindow &window);
    int getX();
    int getY();
    sf::Vector2f getDimensions();
    sf::FloatRect getSpriteGlobalBounds();
    bool intersects(Ship &s);
    bool intersects(Bullet &b);
    void changeSprite();

protected:
    sf::Texture yellow, red;
    sf::Sprite sprite;
};

#endif // BOMB_H
