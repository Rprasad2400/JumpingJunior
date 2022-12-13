#include "Actor.h"
#include "TextureManager.h"

Actor::Actor() {
    running = false;
    animationValue = true;
    velocity.x, velocity.y = 0.0;
    gravity = 0.25f;
    position = mainSprite.getPosition();
    acc.x = 0.0;
    acc.y = 0.0;
} 

sf::Vector2u Actor::getSize() {
        return mainSprite.getTexture()->getSize();

    
}

sf::Vector2f Actor::getPosition()
{
    position = mainSprite.getPosition();
    return position;
}

sf::Sprite Actor::getSprite()
{
    return mainSprite;
}

void Actor::setTextures()
{
    if (animationValue == true) {

        mainSprite.setTexture(TextureManager::getTexture(TexturesPaths[0]));
    }
    else {
        mainSprite.setTexture(TextureManager::getTexture(TexturesPaths[1]));
    }
}



void Actor::setTextures(string name)
{

    mainSprite.setTexture(TextureManager::getTexture(name));
}

bool Actor::isMoving()
{
    return running;
}

void Actor::Update(float time)
{
    move(velocity.x, velocity.y);
    
}



void Actor::setMove(bool run)
{
    running = run;
    if (run) {

        running = true;

    }
    else {
        running = false;
    }
}

void Actor::alternateTextures()
{
    float deltaTime = clock.restart().asSeconds();
    totalTime += deltaTime;
    if (totalTime >= 0.4f) {
        totalTime = 0.0f;
        animationValue = !animationValue;
    }
    setTextures();
}

void Actor::move(float &x, float &y)
{
    mainSprite.move(x, y);
}

void Actor::setTextureRect(int &x, int &y) {
    mainSprite.setTextureRect(sf::IntRect(x, y, 16, 32));
}

void Actor::setPosition(int &x, int &y)
{
    mainSprite.setPosition(x, y);
}
void Actor::setOrigin(float x, float y)
{
    mainSprite.setOrigin(x, y);
}


void Actor::setTextureRect(int x, int y) {
    mainSprite.setTextureRect(sf::IntRect(x, y, 16, 32));
}

void Actor::setPosition(int x, int y)
{
    mainSprite.setPosition(x -getSize().x/2, y -getSize().y/2);
}
