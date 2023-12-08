#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Bomb.h"
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
	void update();
	//void placeBomb();
	void decreaseHp();
	void increaseHp();

private:
	int hp;
	const int hpMax = 2;
};

