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
	bomb.setScale(1.1, 1.1);
	int x = int(cordinate.x + 3);
	int y = int(cordinate.y + 3);
	bomb.setPosition(x - x % 51, y - y % 51);

	float bomb_x = 0;
	for (int i = 0; i < 3; i++)
	{
		bombBar[i].setTexture(bombTex);
		bombBar[i].setPosition(bomb_x, 630.f);
		bomb_x += 40;
	}
}