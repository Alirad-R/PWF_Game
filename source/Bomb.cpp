#include "../header/Bomb.h"

int Bomb::bombCount = 0;

Bomb::Bomb(sf::Vector2f cordinate)
{
	bombTex.loadFromFile("../Images/bomb.png");
	bomb.setTexture(bombTex);

	bomb.setPosition(cordinate.x, cordinate.y);

}