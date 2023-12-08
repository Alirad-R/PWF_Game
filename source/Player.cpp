#include "../header/Player.h"


void Player::initVariables()
{
	this->hpMax = 2;
	this->hp = hpMax;
	this->bombIndex = 2;
	this->keyTime = 0;
}

Player::Player(float x, float y)
{
	initVariables();

	vikingTex.loadFromFile("../Images/viking.png");
	viking.setTexture(vikingTex);
	this->viking.setPosition(x, y);

	bombTex.loadFromFile("../Images/bomb.png");
	float bomb_x = 0;
 	for (int i = 0; i < 3; i++)
	{	
		bomb[i].setTexture(bombTex);
		this->bomb[i].setPosition(bomb_x, 630.f);
		bomb_x += 40;
	}
}

void Player::takeDamage()
{
	hp--;
}

void Player::update()
{
	//Keyboard input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->viking.move(-2.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->viking.move(2.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->viking.move(0.f, -2.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->viking.move(0.f, 2);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && keyTime > 30)
	{
		placeBomb();
		if (bombIndex >= 0)
			bombIndex--;
		keyTime = 0;
	}
	else
		keyTime++;
}

void Player::placeBomb()
{
	bomb[bombIndex].setPosition(viking.getPosition().x, viking.getPosition().y);
}
