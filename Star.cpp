#include "Star.h"

Star::Star()
{
	starBonus = 10;
	starValue = false;
	setTextures("star");
}
Star::Star(const Star& p1) {
	starBonus = p1.starBonus;
	starValue = p1.starValue;
}
Star::~Star() {

}

int Star::returnStarBonus()
{
	return starBonus;
}
bool Star::returnStarValue()
{
	
	return starValue;
}
void Star::setStarValue(bool value) {

	starValue = value;

}

string Star::feefe() {
	return "fefefe";

}


void Star::setStarBonus(int bonus)
{
	starBonus = bonus;
}

void Star::resetPosition()
{
	starValue = false;
	setPosition(350 + rand() % 200, 180);
}
void Star::resetPosition(int distance)
{
	starValue = false;  
	setPosition(350 + (rand() % 200) + distance, 180);
}

