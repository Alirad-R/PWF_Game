#include "../header/Player.h"



Player::Player(float x, float y) :hp(hpMax)
{
	vikingTex.loadFromFile("../Images/viking.png");
	viking.setTexture(vikingTex);
	viking.setPosition(x, y);

	bombTex.loadFromFile("../Images/bomb.png");
	float bomb_x = 0;
 	for (int i = 0; i < 3; i++)
	{	
		bomb[i].setTexture(bombTex);
		bomb[i].setPosition(bomb_x, 630.f);
		bomb_x += 40;
	}
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

//void Player::placeBomb()
//{
//	//bomb[bombIndex].setPosition(viking.getPosition().x, viking.getPosition().y);
//	Bomb bomb(viking.getPosition());
//
//	if (Bomb::bombCount <= 2)
//	{
//		Bomb::bombCount++;
//	}
//}
