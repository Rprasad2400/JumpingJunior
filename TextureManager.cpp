#include "TextureManager.h"
unordered_map<string, sf::Texture> TextureManager::texturePack;
void TextureManager::addTexture(string name) {


	texturePack[name].loadFromFile(name + ".png");

};

 sf::Texture& TextureManager::getTexture(string name) {
	if (texturePack.find(name) == texturePack.end()) {
		addTexture(name);
	}
	return texturePack[name];
};