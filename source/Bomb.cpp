#include "../header/Bomb.h"

int Bomb::bombCount = 0;

Bomb::Bomb()
{
	bombTex.loadFromFile("../Images/bomb.png");
	bomb.setTexture(bombTex);

	float bomb_x = 0;
	for (int i = 0; i < 3; i++)
	{
		//bomb.setScale(0.5, 0.5);
		bombBar[i].setTexture(bombTex);
		bombBar[i].setPosition(bomb_x, 630.f);
		bomb_x += 40;
	}
}
Bomb::Bomb(sf::Vector2f cordinate)
{
	bombTex.loadFromFile("../Images/bomb.png");
	bomb.setTexture(bombTex);
	bomb.setScale(1.2, 1.2);
	int x = int(cordinate.x + 25);
	int y = int(cordinate.y + 25);
	bomb.setPosition(x - x % 52 - 3, y - y % 52 -3);

	float bomb_x = 0;
	for (int i = 0; i < 3; i++)
	{
		bombBar[i].setTexture(bombTex);
		bombBar[i].setPosition(bomb_x, 630.f);
		bomb_x += 40;
	}
}