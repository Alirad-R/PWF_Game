#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>
#include "GameTiles.h"
class GameWorld
{
	sf::Vector2f exitPos;
	sf::Vector2f playerPos;
	std::vector<sf::Vector2f> enemyPositions;
	void setUpInitialState();
	void setUpEnemyPositions();
	void setUpTiles();
public:
	std::vector<std::vector<GameTiles*>> tiles;
	int gridLength;
	GameWorld();
};

