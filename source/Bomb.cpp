#include "../header/Bomb.h"

int Bomb::bombCount = 0;


Bomb::Bomb(sf::Vector2f cordinate)
{
	bombTex.loadFromFile("../Images/bomb.png");
	bomb.setTexture(bombTex);
	int x = int(cordinate.x);
	int y = int(cordinate.y);
	bomb.setPosition(x - x % 52, y - y % 52);

	float bomb_x = 0;
	for (int i = 0; i < 3; i++)
	{
		bombBar[i].setTexture(bombTex);
		bombBar[i].setPosition(bomb_x, 630.f);
		bomb_x += 40;
	}
}