#include "../header/Bomb.h"

int Bomb::bombCount = 0;

Bomb::Bomb(sf::Vector2f cordinate)
{
	bombTex.loadFromFile("../Images/bomb.png");
	bomb.setTexture(bombTex);
	int x = cordinate.x;
	int y = cordinate.y;
	bomb.setPosition(x - x % 52, y - y % 52);
}