#include "EnemyShip.h"
#include "Direction.h"
#include <math.h>

EnemyShip::EnemyShip(int x, int y) : Ship(x, y)
{
   if(!textureForward.loadFromFile("enemyShip.png")) {
        std::cout << "Error loading ship texture - forward" << std::endl;
    }

     if(!textureLeft.loadFromFile("enemyShip_left.png")) {
        std::cout << "Error loading ship - left" << std::endl;
    }

     if(!textureRight.loadFromFile("enemyShip_right.png")) {
        std::cout << "Error loading ship - right" << std::endl;
    }
    sprite.setTexture(textureForward);
    sprite.setPosition(x, y);
    speed = 100.0;
    path.push_back(Direction(90, 200));
    path.push_back(Direction(135, 200));
    path.push_back(Direction(90, 200));
    path.push_back(Direction(45, 200));

}

EnemyShip::~EnemyShip()
{
    //dtor
}

void EnemyShip::followPath(sf::Time &deltaTime) {
    static int i=0;
    static float travelled = 0.0;
    if(travelled < path[i].getDistance()) {
        move(sf::Vector2f(cos(path[i].getAngleInRadians()), sin(path[i].getAngleInRadians())) * deltaTime.asSeconds() * speed);
        travelled += speed * deltaTime.asSeconds();
    }
    else {
        i = (i+1) % path.size();
        travelled = 0.0;
    }

}
