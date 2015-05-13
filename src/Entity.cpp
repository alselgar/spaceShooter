#include "Entity.h"
#include <iostream>

Entity::Entity(char *spritePath, int x, int y)
{
    if(!mainTexture.loadFromFile(spritePath)) {
        std::cout << "Error loading " << spritePath << std::endl;
    }
    mainSprite.setTexture(mainTexture);
    mainSprite.setPosition(x,y);

}

Entity::~Entity()
{
    //dtor
}

void Entity::draw(sf::RenderWindow &window) {
    window.draw(mainSprite);
}

int Entity::getX() {
    return mainSprite.getPosition().x;
}

int Entity::getY() {
    return mainSprite.getPosition().y;
}

sf::Vector2f Entity::getDimensions() {
    sf::FloatRect fr = mainSprite.getGlobalBounds();
    sf::Vector2f dimensions(fr.width, fr.height);
    return dimensions;
}

sf::FloatRect Entity::getSpriteGlobalBounds() {
    return mainSprite.getGlobalBounds();
}

bool Entity::intersects(Entity &e) {
    return mainSprite.getGlobalBounds().intersects(e.getSpriteGlobalBounds());
}




