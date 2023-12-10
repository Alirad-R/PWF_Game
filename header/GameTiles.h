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
	sf::Texture texture;
	sf::Sprite sprite;
	GameTiles(sf::Texture texture, float x = 0, float y = 0, bool passable = true, bool exit = true, bool power = true, bool destructable = true, bool enemy = false);
	bool setUpSprite(std::string, sf::Vector2i loadCounter);
};

