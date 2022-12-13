#include "ScoreBoard.h"
#include <iostream>
using namespace std;

ScoreBoard::ScoreBoard()
{

}

void ScoreBoard::setPosition(int x, int y)
{
	scoreText.setPosition(x, y);

	
}

void ScoreBoard::setFont(sf::Font &font)
{
	scoreText.setFont(font);


}

void ScoreBoard::setSize(int x)
{
	scoreText.setCharacterSize(x);


}

void ScoreBoard::setString(string x)
{
	scoreText.setString(x);


}

ScoreBoard::ScoreBoard(string fontPath, int size, string initalText)
{
	font.loadFromFile(fontPath);
	scoreText.setCharacterSize(size);
	scoreText.setFont(font);
	setPosition(10, 0);
	scoreText.setString(initalText);



}

void ScoreBoard::resetScore()
{
	scoreText.setString("0000");
}


void ScoreBoard::changeScore(string numString)
{
	string precision = "";
	for (int i = 0; i < 4 - numString.length(); i++) {
		precision.append("0");
	}
		numString.insert(0, precision);
	scoreText.setString(numString);
	string y = scoreText.getString();

}

sf::Text ScoreBoard::returnText()
{
	return scoreText;
}


