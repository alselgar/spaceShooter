#ifndef ENEMYSHIP_H
#define ENEMYSHIP_H

#include "Ship.h"
#include "Direction.h"


class EnemyShip : public Ship
{
    public:
        EnemyShip(int x, int y);
    //    Ship(const Ship& orig);
        virtual ~EnemyShip();
        void followPath(sf::Time &deltaTime);

    private:
        std::vector<Direction> path;

};

#endif // ENEMYSHIP_H
