#pragma once
#include <SFML/Graphics.hpp>


class Bomb
{
public:
	static int bombCount;
	sf::Texture bombTex;
	sf::Clock bombTimer;
	sf::Sprite bomb;

	sf::Sprite bombBar[3];

	Bomb(sf::Vector2f cordinate);
private:

	
};

