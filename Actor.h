#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;
class Actor {
protected: 
	bool running;
	bool animationValue;
	vector <string> TexturesPaths;
	sf::Sprite mainSprite;
	float totalTime = 0;
	sf::Vector2f position;
	sf::Vector2f velocity;
	float gravity = 0.5f;
	sf::Vector2f acc;
	sf::Clock clock;

public:
	Actor();
	sf::Vector2u getSize();
	sf::Vector2f getPosition();
	sf::Sprite getSprite();
	void setTextures();
	void setTextureRect(int &x, int &y);
	void setTextures(string name);
	bool isMoving();
	void Update(float time);
	void setMove(bool run);
	void alternateTextures();
	void move(float &x, float &y);
	void setPosition(int &x, int &y);

	void setTextureRect(int x, int y);

	void setPosition(int x, int y);

	void setOrigin(float x, float y);


};