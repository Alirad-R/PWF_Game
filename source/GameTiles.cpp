#include "../header/GameTiles.h"

GameTiles::GameTiles(std::string textureName, float x, float y, bool passable, bool exit, bool power_life, bool power_unlimBomb, bool power_stopEnemy, bool power_speed, bool destructable, bool enemy) {
	/*if (!setUpSprite(textureName)) {
		return;
	}*/
	setUpSprite(textureName);
	pos = sf::Vector2f(x, y);
	sprite.setPosition(pos);
	isPassable = passable;
	isExit = exit;
	isPower_life = power_life;
	isPower_Speed = power_speed;
	isPower_StopEnemy = power_stopEnemy;
	isPower_UnlimBombs = power_unlimBomb;
	isDestroyable = destructable;
	isEnemy = enemy;
}

bool GameTiles::setUpSprite(std::string textureName) {
	if (!texture.loadFromFile(textureName)) {
		return false;
	}
	texture.loadFromFile(textureName);
	texture.setSmooth(true);
	sprite.setTexture(texture);
	//sprite.setTextureRect(sf::IntRect(0, 0, 52, 52));
	return true;
}