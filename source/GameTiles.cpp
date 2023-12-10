#include "../header/GameTiles.h"

GameTiles::GameTiles(sf::Texture texture, float x, float y, bool passable, bool exit, bool power, bool destructable, bool enemy) {
	/*if (!setUpSprite(textureName)) {
		return;
	}*/
	//setUpSprite();
	pos = sf::Vector2f(x, y);
	sprite.setPosition(pos);
	isPassable = passable;
	isExit = exit;
	isPower = power;
	isDestroyable = destructable;
	isEnemy = enemy;
}

bool GameTiles::setUpSprite(std::string textureName, sf::Vector2i loadCounter = sf::Vector2i(0,0)) {
	if (!texture.loadFromFile(textureName)) {
		return false;
	}
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 52, 52));
	return true;
}