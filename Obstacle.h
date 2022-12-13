#pragma once
#include <SFML/Graphics.hpp>
#include "Actor.h"
#include "TextureManager.h"
class Obstacle: public Actor {

public: 
	Obstacle();

	
	
	int resetPosition();
	int resetPosition(int distance);
	int moveDown();
	int moveDown(int val);

};