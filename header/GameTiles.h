#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
class GameTiles
{
public:
	bool isPassable;
	bool isExit;
	bool isPower;
	bool isDestroyable;
	bool isEnemy;
	sf::Vector2f pos;
	//sf::Texture texture;
	//sf::Sprite sprite;
	GameTiles(float x, float y, bool passable, bool exit, bool power, bool destructable, bool enemy = false);
	//bool setUpSprite(std::string);
};

