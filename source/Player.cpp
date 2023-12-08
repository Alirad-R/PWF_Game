#include "../header/Player.h"


void Player::initVariables()
{
	this->hpMax = 2;
	this->hp = hpMax;
}

Player::Player(float x, float y)
{
	initVariables();
	vikingTex.loadFromFile("../Images/viking.png");
	viking.setTexture(vikingTex);
	this->viking.setPosition(x, y);
}

void Player::takeDamage()
{
	hp--;
}

void Player::move()
{
	//Keyboard input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->viking.move(-2.f, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->viking.move(2.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->viking.move(0.f, -2.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->viking.move(0.f, 2);
	}
}
