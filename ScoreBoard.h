#pragma once

#include <SFML/Graphics.hpp>
using namespace std;
#include <vector>
 class ScoreBoard {
	 sf::Text scoreText;
	 sf::Font font;

public:
	ScoreBoard();
	ScoreBoard(string fontPath, int size, string initalText);
	void setPosition(int x, int y);
	void setFont(sf::Font& font);
	void setSize(int x);
	void setString(string x);
	void resetScore();
	void changeScore(string numString);
	sf::Text returnText();


};