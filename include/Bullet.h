#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>

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
    private:
        sf::CircleShape cs;
};

#endif // BULLET_H
