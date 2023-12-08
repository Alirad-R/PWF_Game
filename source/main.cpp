#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <list>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../header/Player.h"

using namespace std;


int main() {
	// -------------------- player -------------------
	Player player(53.f, 53.f);
	list <Bomb*> bombs;
	int keyTime = 0;
	int bombIndex = 3;


	// -------------------- read map from file --------------------
	ifstream openfile("../Images/map2.txt");
	sf::Texture tileTexture;
	sf::Sprite tiles;

	sf::Vector2i map[100][100];
	sf::Vector2i loadCounter = sf::Vector2i(0, 0);

	if (openfile.is_open())
	{
		string tileLocation;
		openfile >> tileLocation;
		tileTexture.loadFromFile(tileLocation);
		tiles.setTexture(tileTexture);

		while (!openfile.eof())
		{
			string str;
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

	// -------------------- window setup--------------------
	const int Screen_width = 570;
	const int Screen_height = 680;

	sf::RenderWindow window(sf::VideoMode(Screen_width, Screen_height), "play with fire");
	window.setFramerateLimit(60);


	// ------------------------ event handlers --------------------
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			if (event.KeyPressed && event.key.code == sf::Keyboard::Escape)
				window.close();
		}

		//---------------------- updater functions -----------------------
		player.update();
		
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && keyTime > 30)
		{
			if (Bomb::bombCount < 3)
			{
				bombs.push_back(new Bomb(player.viking.getPosition()));
				Bomb::bombCount++;
			}

			if (bombIndex >= 0)
				bombIndex--;
			keyTime = 0;
		}
		else
			keyTime++;

		while (bombs.size() > 0 && bombs.front()->bombTimer.getElapsedTime().asSeconds() >= 2)
		{
			//bomb destruction function
			delete bombs.front();
			bombs.pop_front();
			Bomb::bombCount--;
			bombIndex++;
		}



		//---------------------- renderer functions ------------------------
		window.clear();

		for (int i = 0; i < loadCounter.x; i++)
		{
			for (int j = 0; j < loadCounter.y; j++)
			{
				if (map[i][j].x != -1 && map[i][j].y != -1) {
					tiles.setPosition(i * 52, j * 52);
					tiles.setTextureRect(sf::IntRect(map[i][j].x * 52, map[i][j].y * 52, 52, 52));
					window.draw(tiles);
				}
			}
		}

		window.draw(player.viking); //render the player

		for (int i=0; i<bombIndex; i++) //render the bottom bombs
		{
			window.draw(player.bomb[i]);
		}

		for (auto& i : bombs) //render bombs on map
			window.draw(i->bomb);

		window.display();
	}
}