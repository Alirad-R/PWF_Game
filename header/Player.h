#pragma once
#include <iostream>
#include "Bomb.h"
#include "GameTiles.h"
#include "../header/GameTileTypes.h"
#include <SFML/Graphics.hpp>

class Player
{
public:
	//--------------- variables --------------
	sf::Texture vikingTex;
	sf::Sprite viking;

	//--------------- constructor ------------
	Player(float x = 75.f, float y = 75.f);
	//--------------- functions --------------
	void update();
	void decreaseHp();
	void increaseHp();

private:
	int hp;
	const int hpMax = 2;
};

