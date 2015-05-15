#include "Bullet.h"

Bullet::Bullet(int x, int y)
{
    cs.setRadius(3);
    cs.setFillColor(sf::Color(0,0,0));
    cs.setPosition(x,y);
}

Bullet::~Bullet()
{
    //dtor
}

void Bullet::draw(sf::RenderWindow &window) {
    window.draw(cs);
}

void Bullet::update() {
    cs.move(0,-10);
}

int Bullet::getX() {
    return cs.getPosition().x;
}

int Bullet::getY() {
    return cs.getPosition().y;
}

sf::FloatRect Bullet::getCircleShapeGlobalBounds() {
    return cs.getGlobalBounds();
}

bool Bullet::intersects(Entity &e) {
    return cs.getGlobalBounds().intersects(e.getSpriteGlobalBounds());
}
