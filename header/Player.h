#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

class Player
{
public:
	//--------------- variables --------------
	sf::Texture vikingTex;
	sf::Sprite viking;

	sf::Texture bombTex;
	sf::Sprite bomb[3];
	int bombIndex;

	int hp;
	int hpMax;

	int keyTime;
	//--------------- constructor ------------
	Player(float x = 75.f, float y = 75.f);
	//--------------- functions --------------
	void initVariables();
	void update();
	void placeBomb();
	void takeDamage();
};

