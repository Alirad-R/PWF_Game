#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../header/GameTileTypes.h"
class GameTiles
{
public:
	sf::Vector2f pos;
	sf::Texture texture;
	sf::Sprite sprite;
	GameTiles(sf::Texture& texture, float x = 0, float y = 0, GameTile tileType = Destroyable);
	GameTile getTileType();
private:
	GameTile tileType;


};
