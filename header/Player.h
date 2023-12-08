#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

class Player
{
public:
	//--------------- variables --------------
	sf::Texture vikingTex;
	sf::Sprite viking;
	int hp;
	int hpMax;

	//--------------- functions --------------
	void initVariables();
	//void initShape();
	Player(float x = 75.f, float y = 75.f);
	void takeDamage();
	void move();
};

