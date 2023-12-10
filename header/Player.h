#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Bomb.h"
#include "GameTiles.h"

class Player
{
public:
	//--------------- variables --------------
	sf::Texture vikingTex;
	sf::Sprite viking;

	sf::Texture bombTex;
	sf::Sprite bomb[3];
	//int bombIndex;


	//int keyTime;
	//--------------- constructor ------------
	Player(float x = 75.f, float y = 75.f);
	//--------------- functions --------------
	void initVariables();
	void update(GameTiles a);
	//void placeBomb();
	void decreaseHp();
	void increaseHp();

private:
	int hp;
	const int hpMax = 2;
};

