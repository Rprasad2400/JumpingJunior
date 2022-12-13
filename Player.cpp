#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TextureManager.h"
using namespace std;


bool Player::isJumping()
{
    return jumping;
}

void Player::reset() {
    jumping = false;
    falling = false;
    velocity.y = 0.0f;
   setPosition(getSize().x*2, 250);
    running = false;
    jumpHeight = 0.0f;
    setTextures(defaultTexture);
}

bool Player::inContact(Actor &contactee)
{
    float distanceX = getPosition().x - contactee.getPosition().x;
    float distanceY = getPosition().y - contactee.getPosition().y; 
    
    float intersectX = abs(distanceX) - (getSize().x / 2) - (contactee.getSize().x / 2);
    float intersectY = abs(distanceY) - (getSize().y / 2) - (contactee.getSize().y / 2);
    if (intersectX < 0.0f && intersectY < 0.0f) {
        return true;

    }
    else {
        return false;
    }
}

void Player::jump(float groundHeight)
{
    jumpHeight -= velocity.y;
    if (!falling && jumpHeight == 0) {
        velocity.y = gravity - 1.0;
        jumping = true;

    }
    else if (!falling && jumpHeight >= maxHeight) {
        velocity.y = gravity * 0.5;
        jumpHeight -= velocity.y;
        falling = true;

    }
    else if (falling && jumpHeight == 0) {
        velocity.y = 0;
        falling = false;
        jumping = false;

    }
      
    
}


Player::Player() {
    defaultTexture = "Hero";
   TexturesPaths.push_back("Hero_running_1");
   TexturesPaths.push_back("Hero_running_2");
    maxHeight = 125.0;
    jumping = false;
    onGround = true;
    falling = false;
    jumpHeight = 0.0f;
    alternateTextures();
    mainSprite.setOrigin(getSize().x / 2, getSize().y / 2);
    setPosition(getSize().x*2, 250);

}
