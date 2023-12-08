#pragma once
#include <SFML/Graphics.hpp>


class Bomb
{
public:
	static int bombCount;
	sf::Clock bombTimer;
	Bomb(sf::Vector2f cordinate);
	sf::Sprite bomb;
private:
	sf::Texture bombTex;

	
};

