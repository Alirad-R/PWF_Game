#include "../header/GameWorld.h"

GameWorld::GameWorld() {
	gridLength = 12;
	setUpInitialState();

}

void GameWorld::setUpInitialState() {
	exitPos = sf::Vector2f(494, 78);  //i * 52 + 26
	playerPos = sf::Vector2f(78, 78);
	setUpEnemyPositions();
	setUpTiles();
}

void GameWorld::setUpEnemyPositions() {
	enemyPositions.clear();
	enemyPositions.push_back(sf::Vector2f(390, 78));
	enemyPositions.push_back(sf::Vector2f(390, 234));
	enemyPositions.push_back(sf::Vector2f(182, 526));
}

void GameWorld::setUpTiles() {
	tiles.clear();
	std::vector<GameTiles*> firstRow;
	firstRow.push_back(new GameTiles());
	tiles.push_back(firstRow);

	std::vector<GameTiles*> secondRow;
	secondRow.push_back(new GameTiles());
	tiles.push_back(secondRow);
}