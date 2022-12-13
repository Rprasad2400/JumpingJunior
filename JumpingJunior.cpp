#include <SFML/Graphics.hpp>
#include "Player.h"
#include "ScoreBoard.h"
#include "Obstacle.h"
#include <iostream>
#include <stdlib.h>  
#include "Star.h"
#include "Engine.h"

int main()
{
    //TODO: Seperate this into its own class
    //TODO: Fix the texture difference in size 

/*
    sf::Font font;
    font.loadFromFile("RalewayBold.ttf");
    //Renders Window with height and width
    sf::RenderWindow window(sf::VideoMode(400, 400), "Jumping Junior");


    //Initalizes floor of JJ at 250
    sf::RectangleShape shape(sf::Vector2f(400, 5.f));
    shape.setPosition(0, 250);
    shape.setFillColor(sf::Color::White);

    ScoreBoard scoreboard("RalewayBold.ttf", 30, "0000");
    //creates the obstacle and Protag
    Player hero;

    sf::Text text("Congratulations", font, 30);
    text.setPosition(window.getSize().x / 3, window.getSize().y / 3);
    text.setFillColor(sf::Color::White);

    Obstacle obstacles[2];
    Star whiteStar;
    obstacles[0].setPosition(350, 250- obstacles[0].getSize().y);
    obstacles[1].setPosition(350, 250 - obstacles[1].getSize().y);
    whiteStar.setPosition(380, 180 - whiteStar.getSize().y);



    float totalTime = 0.0;

    sf::Clock gameClock;
    sf::Clock clock;
    bool gameOver = false;
    bool winGame = false;
    float speedIncrease = 0.0;
    int bonus = 0;

    */
    sf::RenderWindow window(sf::VideoMode(400, 400), "Jumping Junior");
    Engine engine(window);
    
    engine.fullGame();
        /*
            sf::Event event;
            if (!gameOver && !winGame) {
                //gameTime
              float startTime = gameClock.getElapsedTime().asSeconds();
                int num = ((int)startTime + bonus);
                string numString = to_string(num);
                if (num >= 100) {
                    gameOver = true;
                    winGame = true;
                }
                scoreboard.changeScore(numString);



              obstacles[0].moveDown();
               obstacles[1].moveDown();
                whiteStar.moveDown();
                //when Player is not moving, do set Animation
                if (!hero.isMoving()) {
                    //sets animation
                    hero.alternateTextures();
                }


                //Player isnt touching obstacle -> perform movement
            if (!hero.inContact(obstacles[0]) || !hero.inContact(obstacles[1])) {
                    if (hero.isJumping()) {
                        float deltaTime = clock.restart().asSeconds();
                        totalTime += deltaTime;
                        if (totalTime >= 0.003f) {
                            hero.jump();
                            totalTime = 0.0f;
                        }
                    }



                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                        if (!hero.isJumping()) {
                            hero.jump();

                        }

                    }

                }
                else {
                    gameOver = true;

                }


            //star properties
            //make this into a subclass

                if (hero.inContact(whiteStar) && (whiteStar.returnStarValue() == false)) {
                    bonus = bonus + 10;
                    whiteStar.setStarValue(true);
                }

                if (whiteStar.returnStarValue()) {
                    if (whiteStar.getPosition().x < 0.0) {

                    }
                 }



                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed) {
                        window.close();
                    }





                }
            }
            //if you win the game
            else if(winGame && gameOver) {
                obstacles[0].setPosition(250, 250);
                obstacles[1].resetPosition();
                whiteStar.resetPosition();
                if (hero.getPosition().x >= 250) {


                }
                else {
                    hero.move(0.25, 0);
                    hero.alternateTextures();

                }
            }

            else if (gameOver && !winGame) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    gameOver = false;
                     totalTime = 0.0;
                    gameClock.restart().asSeconds();
                    obstacles[0].setPosition(300, 250-obstacles[0].getSize().y);
                    obstacles[1].resetPosition();
                    whiteStar.setPosition(350, 180 - whiteStar.getSize().y);
                    whiteStar.setStarValue(false);
                    hero.reset();
                    bonus = false;
                    hero.setPosition(hero.getSize().x, 250 - hero.getSize().y/2);
                    winGame = false;


                }
            }


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
        */
    
    return 0;
}
