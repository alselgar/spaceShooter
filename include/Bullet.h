#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Bullet
{
    public:
        Bullet(int x, int y);
        virtual ~Bullet();
        void draw(sf::RenderWindow &window);
        void update();
        int getX();
        int getY();
        sf::FloatRect getCircleShapeGlobalBounds();
        bool intersects(Entity &e);
    private:
        sf::CircleShape cs;
};

#endif // BULLET_H
