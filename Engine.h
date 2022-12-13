#pragma once
#include <SFML/Graphics.hpp>
#include "ScoreBoard.h"
#include "Obstacle.h"
#include "Player.h"
#include "Star.h"
class Engine {
	sf::Event event;
	sf::Clock gameClock;
	sf::Clock clock;
	float totalTime;
	sf::Text text;
	int bonus;
	Obstacle* firstPlace;
	Obstacle* secondPlace;
	sf::Font font;
	float groundHeight;
	bool gameOver;
	sf::RenderWindow& window;
	bool winGame;
	Player hero;
	sf::RectangleShape shape;
	ScoreBoard scoreboard;
	Obstacle obstacles[2];
	Star whiteStar;
	
public:

	void setScore();
	void moveAssets(float time);
	void moveObstacles();
	void heroJump();
	void fullGame();
	void draw();
	void victoryRun();
	bool checkContact();

	void inGame();

	void gameLoss();
	void resetGame();


	Engine(sf::RenderWindow & window);

	bool getGameOver();

	bool getStarValue();
	

	

};