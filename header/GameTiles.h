#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
class GameTiles
{
public:
	bool isPassable;
	bool isExit;
	bool isPower_life;
	bool isPower_UnlimBombs;
	bool isPower_StopEnemy;
	bool isPower_Speed;
	bool isDestroyable;
	bool isEnemy;
	sf::Vector2f pos;
	sf::Texture texture;
	sf::Sprite sprite;
	GameTiles(std::string texture, float x = 0, float y = 0, bool passable = true, bool exit = true, bool power_life = true, bool power_unlimBomb = true, bool power_stopEnemy = true, bool power_speed = true, bool destructable = true, bool enemy = false);
	bool setUpSprite(std::string textureName);
};

