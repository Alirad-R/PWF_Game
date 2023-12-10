#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <list>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../header/Player.h" 
#include "../header/GameTiles.h"

using namespace std;


int main() {
	// -------------------- objects -------------------
	Player player(53.f, 53.f);
	list <Bomb*> bombs;
	int keyTime = 0;
	int bombIndex = 3;
	vector<GameTiles> tile;

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
		for (auto i : tile)
		{ 
			if (player.viking.getGlobalBounds().intersects(i.sprite.getGlobalBounds()))
				player.update(i);
		}

		
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && keyTime > 30)
		{
			if (Bomb::bombCount < 3)
			{
				bombs.push_back(new Bomb(player.viking.getPosition()));
				Bomb::bombCount++;
			}

			if (bombIndex > 0)
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
					if (map[i][j].x == 1 && map[i][j].y == 1) // InDestructable block
					{
						tile.push_back(GameTiles("../Images/InDestructable_Wall.png", i * 52, j * 52, false, false, false, false, false, false, false, false));
					}
					else if (map[i][j].x == 2 && map[i][j].y == 0) // Destructable block
					{ 
						tile.push_back(GameTiles("../Images/Destructable_Wall.png", i * 52, j * 52, false, false, false, false, false, false, true, false));
					}
					else if (map[i][j].x == 0 && map[i][j].y == 0)  // Power Up life
					{
						tile.push_back(GameTiles("../Images/Add_life_power_2.png", i * 52, j * 52, true, false, true, false, false, false, false, false));
					}
					else if (map[i][j].x == 1 && map[i][j].y == 2) // Power Up Unlimited bombs
					{ 
						tile.push_back(GameTiles("../Images/Unlimited_Bombs_power_1.png", i * 52, j * 52, true, false, false, true, false, false, false, false));
					}
					else if (map[i][j].x == 0 && map[i][j].y == 2) // Power UP Stop Enemy
					{ 
						tile.push_back(GameTiles("../Images/Stop_Enemy_power_3.png", i * 52, j * 52, true, false, false, false, true, false, false, false));
					}
					else if (map[i][j].x == 0 && map[i][j].y == 1) // Power UP Speed
					{ 
						tile.push_back(GameTiles("../Images/Increase_speed_power_4.png", i * 52, j * 52, true, false, false, false, false, true, false, false));
					}
					else if (map[i][j].x == 3 && map[i][j].y == 1) // Locked Door
					{ 
						tile.push_back(GameTiles("../Images/Locked_Door.png", i * 52, j * 52, true, false, false, false, false, false, false, false));
					}
					else if (map[i][j].x == 2 && map[i][j].y == 2) // Unlocked Door
					{ 
						tile.push_back(GameTiles("../Images/Unlocked_Door.png", i * 52, j * 52, true, true, false, false, false, false, false, false));
					}
					else if (map[i][j].x == 3 && map[i][j].y == 0) // Enemy
					{ 
						tile.push_back(GameTiles("../Images/Enemy.png", i * 52, j * 52, true, false, false, false, false, false, true, true));
					}
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