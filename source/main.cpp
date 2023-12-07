#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;

int main() {

	std::ifstream openfile("map2.txt");
	sf::Texture tileTexture;
	sf::Sprite tiles;

	sf::Vector2i map[100][100];
	sf::Vector2i loadCounter = sf::Vector2i(0, 0);
	if (openfile.is_open())
	{
		std::string tileLocation;
		openfile >> tileLocation;
		tileTexture.loadFromFile(tileLocation);
		tiles.setTexture(tileTexture);
		while (!openfile.eof())
		{
			std::string str;
			openfile >> str;
			char x = str[0], y = str[2];
			if (!isdigit(x) || !isdigit(y))
			{
				map[loadCounter.x][loadCounter.y] = sf::Vector2i(-1, -1);
			}
			else
			{
				map[loadCounter.x][loadCounter.y] = sf::Vector2i(x - '0', y - '0');
			}

			if (openfile.peek() == '\n')
			{
				loadCounter.x = 0;
				loadCounter.y = loadCounter.y + 1;
			}
			else
			{
				loadCounter.x = loadCounter.x + 1;
			}

		}
		loadCounter.y = loadCounter.y + 1;
	}

	const int Screen_width = 1000;
	const int Screen_height = 1000;
	int refresh_rate = 100;

	sf::RenderWindow window(sf::VideoMode(Screen_width, Screen_height), "SFML works");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear();

		for (int i = 0; i < loadCounter.x; i++)
		{
			for (int j = 0; j < loadCounter.y; j++)
			{
				if(map[i][j].x != -1 && map[i][j].y != -1){
					tiles.setPosition(i * 52, j * 52);
					tiles.setTextureRect(sf::IntRect(map[i][j].x * 52, map[i][j].y * 52, 52, 52));
					window.draw(tiles);
				}
			}
		}

		window.display();
	}
}