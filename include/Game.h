#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Ship.h"
#include "EnemyShip.h"
#include "Bullet.h"

//const int mapLength = 6000;
const int resX = 640;
const int resY = 480;
const int tileSize = 50;

class Game
{
    public:
        Game();
        ~Game();
        void run();

    private:
        void processEvents();
        void update(sf::Time deltaTime);
        void render();
        void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

        sf::RenderWindow *mWindow;
        bool mIsMovingUp, mIsMovingDown, mIsMovingLeft, mIsMovingRight;
        float playerSpeed;
        sf::Time timePerFrame;

        sf::Texture backgroundTexture;
        sf::Sprite backgroundSprite;
        int mapWidth, mapLength;

        Ship *playerShip;

        //Testing views
        sf::View gameView;

        //Bullet list
        std::vector<Bullet> bulletList;

        //Enemy list
        std::vector<EnemyShip> enemyList;

        sf::Font font;
        sf::Text text;

};

#endif // GAME_H
