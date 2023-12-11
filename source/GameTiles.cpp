#include "../header/GameTiles.h"

//GameTiles::GameTiles(std::string textureName, float x, float y, bool passable, bool exit, bool power_life, bool power_unlimBomb, bool power_stopEnemy, bool power_speed, bool destructable, bool enemy) {
//	/*if (!setUpSprite(textureName)) {
//		return;
//	}*/
//	setUpSprite(textureName);
//	pos = sf::Vector2f(x, y);
//	sprite.setPosition(pos);
//	isPassable = passable;
//	isExit = exit;
//	isPower_life = power_life;
//	isPower_Speed = power_speed;
//	isPower_StopEnemy = power_stopEnemy;
//	isPower_UnlimBombs = power_unlimBomb;
//	isDestroyable = destructable;
//	isEnemy = enemy;
//}


GameTiles::GameTiles(sf::Texture& texture, float x, float y, gameTile tileType)
{
	/*if (!setUpSprite(textureName))
		throw 0;*/

	this->texture = texture;
	pos = sf::Vector2f(x, y);
	sprite.setTexture(this->texture);
	sprite.setPosition(pos);
	this->tileType = tileType;
}


gameTile GameTiles::getTileType()
{
	return tileType;
}