#include "../header/Player.h"


Player::Player(float x, float y) :hp(hpMax)
{
	vikingTex.loadFromFile("../Images/viking.png");
	viking.setTexture(vikingTex);
	viking.setPosition(x, y);
}

void Player::decreaseHp(){ hp--; }

void Player::increaseHp(){ hp++; }

void Player::update()
{
	//Keyboard input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		viking.move(-2.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		viking.move(2.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		viking.move(0.f, -2.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		viking.move(0.f, 2);
	}
}
