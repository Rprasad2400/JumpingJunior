#pragma once
using namespace std;
#include <vector>
#include <SFML/Graphics.hpp>
#include <unordered_map>


#include <iostream>
 class TextureManager {
	static unordered_map<string, sf::Texture> texturePack;
public: 
	static void addTexture(string name);
	static sf::Texture& getTexture(string name);
	



	

};