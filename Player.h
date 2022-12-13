#pragma once
#include <SFML/Graphics.hpp>
#include "Actor.h"
#include <vector>
using namespace std;
class Player: public Actor {


	bool jumping;
	bool falling;
	float maxHeight;
	bool onGround;
	string defaultTexture;
	float totalTime = 0;
	float jumpHeight;
	sf::Clock clock;

public:
	Player();
	void reset();
	bool isJumping();
	bool inContact(Actor &contactee);

	void jump(float groundHeight);
	
};