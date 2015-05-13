#ifndef ENTITY_H
#define ENTITY_H

#include "SFML/Graphics.hpp"
#include "Bullet.h"

class Entity
{
    public:
        Entity(char *spritePath, int x, int y);
        virtual ~Entity();
        void draw(sf::RenderWindow &window);
        int getX();
        int getY();
        sf::Vector2f getDimensions();
        sf::FloatRect getSpriteGlobalBounds();
        bool intersects(Entity &e);
        bool intersects(Bullet &b);

    protected:
        sf::Texture mainTexture;
        sf::Sprite mainSprite;
    private:

};

#endif // ENTITY_H
