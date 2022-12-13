#include <SFML/Graphics.hpp>
#include "Obstacle.h"
#include "TextureManager.h"
Obstacle::Obstacle() {
    setTextures("Red Obstacle");
    mainSprite.setOrigin(getSize().x / 2, getSize().y / 2);

};

int Obstacle::moveDown()
{
    velocity.x = -0.15f;
    if (getPosition().x < 0.0) {
       return resetPosition();
       
    }
    return -1;
    
}

int Obstacle::moveDown(int val)
{
    velocity.x = -0.15f;
    if (getPosition().x < 0.0) {
        return resetPosition(val);

    }
    return -1;

}

int Obstacle::resetPosition() {
    velocity.x = 0.0f;
    int x = 400 + rand() % 200;
    setPosition(x, 250);
    return x;
}
int Obstacle::resetPosition(int distance) {
    velocity.x = 0.0f;
    int r = rand() %50 +150;
    setPosition(distance+r, 250);
    return 80 + distance;
}
