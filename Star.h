#pragma once
#include "Obstacle.h"
class Star : public Obstacle {
	int starBonus;
	bool starValue;
 public:
	 Star();
	 ~Star();
	 Star(const Star& p1);
	 Star& operator=(const Star& t) {
		 starBonus = t.starBonus;
		 starValue = t.starValue;
	 }
	 int returnStarBonus();
	 bool returnStarValue();
	 void setStarValue(bool value);
	 string feefe();
	 void setStarBonus(int bonus);
	 void resetPosition();
	 void resetPosition(int distance);
};