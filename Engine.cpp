#include "Engine.h"
using namespace std;



void Engine::setScore()
{

    int num = ((int)totalTime + bonus);
    string numString = to_string(num);
    if (num >= 100) {
        winGame = true;
    }
    scoreboard.changeScore(numString);

}

void Engine::moveAssets(float time) {
    
    obstacles[0].Update(time);
    obstacles[1].Update(time);
    whiteStar.Update(time);
    hero.Update(time);
    firstPlace = &obstacles[0];
    secondPlace =&obstacles[1];

}
void Engine::moveObstacles()
{
    
    int val = obstacles[0].moveDown();

    if (firstPlace->getPosition().x < 0) {
        if (secondPlace->getPosition().x > 300) {
            int m = secondPlace->getPosition().x;
            firstPlace->moveDown(m);
         }
        Obstacle* temp = firstPlace;
        firstPlace = secondPlace;
        secondPlace = temp;
    }
    else {
        firstPlace->moveDown();
    }
    secondPlace->moveDown();
    whiteStar.moveDown();
}

void Engine::heroJump()
{
    if (!hero.isMoving()) {
        //sets animation
        hero.alternateTextures();
    }


    //Player isnt touching obstacle -> perform movement
    if (!hero.inContact(obstacles[0]) && !hero.inContact(obstacles[1])) {
        if (hero.isJumping()) {

            hero.jump(groundHeight);
        }



        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            if (!hero.isJumping()) {
                hero.jump(groundHeight);

            }

        }

    }
    else {
        gameOver = true;

    }


}

void Engine::fullGame() {
    while (window.isOpen())
    {
        sf::Event event;
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

        }
        
        inGame();
        draw();

        
    }
}
void Engine::draw() {

    window.clear();
    window.draw(shape);

    window.draw(hero.getSprite());
    if (!winGame) {

        window.draw(obstacles[0].getSprite());
        window.draw(obstacles[1].getSprite());
        window.draw(scoreboard.returnText());

        if (!whiteStar.returnStarValue()) {

            window.draw(whiteStar.getSprite());
        }
    }
    else {
        window.draw(text);

    }
    window.display();


}

void Engine::victoryRun()
{
    obstacles[0].setPosition(250, 250);
    obstacles[1].resetPosition();
    whiteStar.resetPosition();
    if (hero.getPosition().x >= 250) {


    }
    else {
        hero.alternateTextures();

    }


}
bool Engine::checkContact() {
    if (hero.inContact(obstacles[1]) && hero.inContact(obstacles[0])) {
        gameOver = true;
    }

    if (hero.inContact(whiteStar)) {
        bonus = 10;
        whiteStar.setStarValue(true);
        
    }
    return gameOver;
}

void Engine::inGame() {
    if (!checkContact() && !winGame) {
        totalTime = clock.getElapsedTime().asSeconds();
        setScore();
        moveAssets(totalTime);
        moveObstacles();
        heroJump();

    }
    else if (winGame) {
        victoryRun();
        gameLoss();
    }
    else {
        gameLoss();
    }

}

void Engine::gameLoss()
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        resetGame();

    }
}

void Engine::resetGame()
{
        gameOver = false;
        obstacles[1].setTextures("SpikeObstacle");
        bonus = 0;
        winGame = false;
        totalTime = 0.0;
        clock.restart().asSeconds();
        int value = obstacles[0].resetPosition();
        obstacles[1].resetPosition(value);
        whiteStar.setPosition(350, 180);

        hero.reset();


    
}

Engine::Engine(sf::RenderWindow &win) :window(win) {
    font.loadFromFile("RalewayBold.ttf");
    groundHeight = 400.0;
    sf::RectangleShape shapeA(sf::Vector2f(groundHeight, 5.f));
    shape = shapeA;
    shape.setPosition(0, 250);
    shape.setFillColor(sf::Color::White);

    scoreboard.setFont(font);
    scoreboard.setSize(30);
    scoreboard.setString("0000");
   //TODO:implement basic features



    text.setFont(font);
    text.setString("Congrats");
    text.setCharacterSize(30);
   text.setPosition(window.getSize().x / 3, window.getSize().y / 3);
   text.setFillColor(sf::Color::White);



   obstacles[0].setPosition(350, 250);
   obstacles[1].setPosition(350, 250);
   whiteStar.setPosition(380, 180);



   float totalTime = 0.0;

   sf::Clock gameClock;
   sf::Clock clock;
   bool gameOver = false;
   bool winGame = false;
   float speedIncrease = 0.0;
   int bonus = 0;
}

bool Engine::getGameOver() {
    return gameOver;
}
bool Engine::getStarValue() {
    return whiteStar.returnStarValue();
}



