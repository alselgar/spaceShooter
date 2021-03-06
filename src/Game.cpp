#include "Game.h"
#include "Map.h"

Game::Game() {

    mWindow = new sf::RenderWindow(sf::VideoMode(640, 480), "SFML Application");

    Map testMap = Map("mapFile");
    testMap.printMatrix();

    mapWidth = tileSize * testMap.getnumTilesY();
    mapLength = tileSize * testMap.getnumTilesX();


    gameView = sf::View(sf::FloatRect(0, mapLength-500, resX, resY));
    mIsMovingDown = mIsMovingLeft = mIsMovingUp = mIsMovingRight = false;
    playerSpeed = 150.0;
    timePerFrame = sf::seconds(1.f / 60.f);

    if(!backgroundTexture.loadFromFile("tile.png")) {
        // Loading error
        std::cout << "Error loading tile texture" << std::endl;
    }


    backgroundTexture.setRepeated(true);
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0.f, 0.f);
    backgroundSprite.setTextureRect(sf::IntRect(0.f, 0.f, mapWidth, mapLength));

    playerShip = new Ship((resX/2) - 25, mapLength-100);
    playerShip->setSpeed(playerSpeed);


    //static EnemyShip testEnemy1(250, 5000); // has to be static to be displayed
    //static EnemyShip testEnemy2(500, 5000);

    //enemyList.push_back(testEnemy1);
    //enemyList.push_back(testEnemy2);
    char **m = testMap.getMapMatrix();
    for(int i=0; i<testMap.getnumTilesX(); i++) {
        for(int j=0; j<testMap.getnumTilesX(); j++) {
            switch (m[i][j]) {
                case 'e':
                {
                    EnemyShip *e = new EnemyShip(j*tileSize, i*tileSize);
                    enemyList.push_back(*e);
                    break;
                }
                case 'b':
                {
                    Bomb *b = new Bomb(j*tileSize, i*tileSize);
                    bombList.push_back(*b);
                    break;
                }
                default:
                    break;
            }
        }
    }

    if(!font.loadFromFile("arial.ttf"))
        std::cout << "Error loading font" << std::endl;

    text.setFont(font);
    text.setColor(sf::Color::Red);
    text.setString("Probando...");
    text.setPosition(25, 5900);

    //Testing maps
    //Map testMap = Map(15, 10);

   // bullet = Bullet(playerShip.getX(), playerShip.getY());

    //Testing Views
    //gameView.reset(sf::FloatRect(0, 5520, 640, 480));
    //gameView.setCenter(100, 100);
    //gameView.rotate(20);


}

Game::~Game() {
    //dtor
}

void Game::run() {

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while(mWindow->isOpen()) {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while(timeSinceLastUpdate > timePerFrame) { //it's time to update the game (not render)
            timeSinceLastUpdate -= timePerFrame;    // we "reset" timeSinceLastUpdate, a timePerFrame has passed
            processEvents();
            update(timePerFrame);    //timePerFrame is a constant value for every iteration
        }

        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (mWindow->pollEvent(event)) {

        switch(event.type) {

            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                mWindow->close();
                break;
            default:
                break;

        }
    }
}

void Game::update(sf::Time deltaTime) {

    //Checking map bounds
    if(playerShip->getX() < 0)
        playerShip->moveTo(0, playerShip->getY());
    if(playerShip->getX() > resX-playerShip->getDimensions().x)
        playerShip->moveTo(resX-playerShip->getDimensions().x, playerShip->getY());

    sf::Vector2f playerShip_movement(0.f, 0.f);

    if(mIsMovingUp)
        playerShip_movement.y -= playerSpeed;
    if(mIsMovingDown)
        playerShip_movement.y += playerSpeed;
    if(mIsMovingLeft)
        playerShip_movement.x -= playerSpeed;
    if(mIsMovingRight)
        playerShip_movement.x += playerSpeed;

    //Updates ship, camera position, text position
    playerShip_movement = playerShip_movement * deltaTime.asSeconds();
    playerShip->move(playerShip_movement);
    gameView.move(0, playerShip_movement.y);
    text.move(0, playerShip_movement.y);

    mWindow->setView(gameView);
//    std::cout << "Posicion de la nave: posx " << playerShip.getX()  << " posy " << playerShip.getY() << std::endl;
//    std::cout << "Centro de la camara: centerx " << gameView.getCenter().x  << " centery " << gameView.getCenter().y << std::endl;

    //Updates the bullet list
    for(int i =0; i<bulletList.size(); i++) {
        bulletList[i].update();
        if(bulletList[i].getY() > mapLength)
            bulletList.erase(bulletList.begin()+i);
    }

    //Check collisions between player and enemies
    for(int i=0; i<enemyList.size(); i++) {
        if(playerShip->intersects(enemyList[i])) {
            enemyList.erase(enemyList.begin()+i); // The enemy is destroyed
            std::cout << "Collission detected with enemy ship " << i << std::endl;
        }
    }

    for(int i=0; i<bombList.size(); i++) {
        if(playerShip->intersects(bombList[i])) {
            bombList.erase(bombList.begin()+i); // The enemy is destroyed
            std::cout << "Collission detected with bomb " << i << std::endl;
        }
    }


    //Check collisions between bullets and enemies

    for(int i=0; i<bulletList.size(); i++) {
        for(int j=0; j<enemyList.size(); j++) {
            if(bulletList[i].intersects(enemyList[j])) {
                bulletList.erase(bulletList.begin()+i); // The bullet is destroyed
                enemyList.erase(enemyList.begin()+j); // The enemy is destroyed
               std::cout << "Bullet " << i << " hits " << "enemy " << j << std::endl;
            }
        }
        for(int j=0; j<bombList.size(); j++) {
            if(bulletList[i].intersects(bombList[j])) {
                bulletList.erase(bulletList.begin()+i); // The bullet is destroyed
                bombList.erase(bombList.begin()+j); // The bomb is destroyed
               std::cout << "Bullet " << i << " hits " << "bomb " << j << std::endl;
            }
        }
    }

    // Move enemy ships
    for(int i=0; i<enemyList.size(); i++) {
        enemyList[i].followPath(deltaTime);
    }

}

void Game::render() {
    mWindow->clear();
    mWindow->draw(backgroundSprite);
    playerShip->draw(*mWindow);
    //draws the bullets
    for(int i=0; i<bulletList.size(); i++)
        bulletList[i].draw(*mWindow);
    //draws the enemies
    for(int i=0; i<enemyList.size(); i++)
        enemyList[i].draw(*mWindow);

    //draws the bombs
    for(int i=0; i<bombList.size(); i++)
        bombList[i].draw(*mWindow);

    //std::cout << "Enemy list size: " << enemyList.size() << std::endl;
    mWindow->draw(text);
    mWindow->display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {

    if(key == sf::Keyboard::W || key == sf::Keyboard::Up)
        mIsMovingUp = isPressed;

    else if(key == sf::Keyboard::S || key == sf::Keyboard::Down)
        mIsMovingDown = isPressed;

    else if(key == sf::Keyboard::A || key == sf::Keyboard::Left)
        mIsMovingLeft = isPressed;

    else if(key == sf::Keyboard::D || key == sf::Keyboard::Right)
        mIsMovingRight = isPressed;

    else if(key == sf::Keyboard::Space && isPressed == false)
        bulletList.push_back(Bullet(playerShip->getX() + playerShip->getDimensions().x /2, playerShip->getY()));

    else if(key == sf::Keyboard::Escape)
        exit(0);
}

