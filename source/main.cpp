#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <list>
#include <sstream>
#include <iomanip>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../header/Player.h"
#include "../header/GameTiles.h"
#include "../header/GameTileTypes.h"
#include "../header/Menu.h"
#include "../header/OptionMenu.h"
#include "../header/Enemy.h"

using sf::Texture;
using namespace std;

enum GameState {
	MENU,
	OPTIONS_MENU,
	PLAYING
};

GameState currentSate = MENU;

int main();

void loadMapTextures
(
	Texture* border,
	Texture* passable,
	Texture* destructableBlock,
	Texture* exitLocked,
	Texture* exitUnlocked,
	Texture* powerLife,
	Texture* powerUnlimBomb,
	Texture* powerStopEnemy,
	Texture* powerSpeed,
	Texture* enemy
);

int main()
{
	// -------------------- initialize -------------------
	const int countdownDuration = 200;
	sf::Clock timerClock;
	//sf::Time timerTime = sf::seconds(countdownDuration);


	Player player(53.f, 53.f);
	list <Bomb*> bombs;
	Bomb dummyBomb;
	int keyTime = 0;
	int bombIndex = 3;
	vector<GameTiles*> tile;
	vector<GameTiles*> enemies;
	sf::Sprite bombSprite;

	Texture border,
		passable, destructable, exitLock,
		exitUnlock, powerLife, powerUnlimBomb,
		powerStopEnemy, powerSpeed, enemy;

	loadMapTextures(&border, &passable, &destructable, &exitLock, &exitUnlock, &powerLife
		, &powerUnlimBomb, &powerStopEnemy, &powerSpeed, &enemy);
	sf::Vector2f vikingPrevPosition;
	sf::Vector2f vikingPrev;
	gameTile mytile;
	bool touch = false;

	// -------------------- window setup --------------------
	const int Screen_width = 570;
	const int Screen_height = 680;

	sf::RenderWindow window(sf::VideoMode(Screen_width, Screen_height), "play with fire");
	window.setFramerateLimit(60);

	// -------------------- Render Menu ---------------------
	Menu menu(window.getSize().x, window.getSize().y);
	OptionsMenu optionMenu(window.getSize().x, window.getSize().y);

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
	// --------------------- initialize map -----------------

	for (int i = 0; i < loadCounter.x; i++)
	{
		for (int j = 0; j < loadCounter.y; j++)
		{
			if (map[i][j].x != -1 && map[i][j].y != -1) {
				tiles.setPosition(i * 52, j * 52);
				tiles.setTextureRect(sf::IntRect(map[i][j].x * 52, map[i][j].y * 52, 52, 52));
				if (map[i][j].x == 1 && map[i][j].y == 1) // InDestructable block
				{
					tile.push_back(new GameTiles(border, i * 52, j * 52, Border));
				}
				else if (map[i][j].x == 2 && map[i][j].y == 0) // Destructable block
				{
					tile.push_back(new GameTiles(destructable, i * 52, j * 52, Destroyable));
				}
				else if (map[i][j].x == 0 && map[i][j].y == 0)  // Power Up life
				{
					tile.push_back(new GameTiles(powerLife, i * 52, j * 52, Power_life));
				}
				else if (map[i][j].x == 1 && map[i][j].y == 2) // Power Up Unlimited bombs
				{
					tile.push_back(new GameTiles(powerUnlimBomb, i * 52, j * 52, Power_UnlimBombs));
				}
				else if (map[i][j].x == 0 && map[i][j].y == 2) // Power UP Stop Enemy
				{
					tile.push_back(new GameTiles(powerStopEnemy, i * 52, j * 52, Power_StopEnemy));
				}
				else if (map[i][j].x == 0 && map[i][j].y == 1) // Power UP Speed
				{
					tile.push_back(new GameTiles(powerSpeed, i * 52, j * 52, Power_Speed));
				}
				//else if (map[i][j].x == 2 && map[i][j].y == 2) // Unlocked Door
				//{
				//	tile.push_back(new GameTiles(exitUnlock, i * 52, j * 52, ExitUnlocked));
				//}
				else if (map[i][j].x == 3 && map[i][j].y == 1) // Locked Door
				{
					tile.push_back(new GameTiles(exitLock, i * 52, j * 52, ExitLocked));
				}
				else if (map[i][j].x == 3 && map[i][j].y == 0) // Enemy
				{
					tile.push_back(new GameTiles(enemy, i * 52, j * 52, Enemy));
					//enemies.push_back(tile.back());
				}

			}
		}
	}



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

			if (event.type == sf::Event::KeyPressed) {
				if (currentSate == MENU)
				{
					if (event.key.code == sf::Keyboard::Up)
					{
						menu.MoveUp();
					}
					else if (event.key.code == sf::Keyboard::Down)
					{
						menu.MoveDown();
					}
					else if (event.key.code == sf::Keyboard::Return)
					{
						switch (menu.GetPressedItem())
						{
						case 0:
							std::cout << "Play button has been pressed" << std::endl;
							currentSate = PLAYING;
							break;
						case 1:
							std::cout << "Option button has been pressed" << std::endl;
							currentSate = OPTIONS_MENU;
							
							break;
						case 2:
							window.close();
						}
					}
				}
				else if (currentSate == OPTIONS_MENU)
				{
					if (event.key.code == sf::Keyboard::Up)
					{
						optionMenu.MoveUp();
					}
					else if (event.key.code == sf::Keyboard::Down)
					{
						optionMenu.MoveDown();
					}
					else if (event.key.code == sf::Keyboard::Return) {
						switch (optionMenu.GetPressedItem()) {
						case 0:
							std::cout << "Help option selected" << std::endl;
							optionMenu.DisplayHelp(window);
							break;
						case 1:
							std::cout << "Back option selected" << std::endl;
							currentSate = MENU;
							break;
							// Add more options handling as needed
						}
					}
				}
				else if (currentSate == PLAYING)
				{

				}
			}
		}

		//---------------------- updater functions -----------------------
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
			//bombSprite = bombs.front()->bomb;
			if (player.viking.getGlobalBounds().intersects(bombs.front()->bomb.getGlobalBounds()))
				player.decreaseHp();

			b: for (auto &i : tile)
			{
				if (i->sprite.getGlobalBounds().intersects(bombs.front()->bomb.getGlobalBounds()))
				{
					switch (i->getTileType())
					{
						case Enemy:
						{
							remove(tile.begin(), tile.end(), i);
							break;
						}
						case Destroyable:
						{
							remove(tile.begin(), tile.end(), i);
							goto b;
							break;
						}
					}
				}

			}
			delete bombs.front();
			bombs.pop_front();
			Bomb::bombCount--;
			bombIndex++;
		}


		mytile = Passable;
		touch = false;
		vikingPrev = player.viking.getPosition();
		for (auto &i : tile)
		{
			if (player.viking.getGlobalBounds().intersects(i->sprite.getGlobalBounds()))
			{
				mytile = i->getTileType();
				touch = true;
			}
			//if (bombSprite.getGlobalBounds().intersects(i->sprite.getGlobalBounds()))
			//{
			//	switch (i->getTileType())
			//	{
			//		case Enemy:
			//		{
			//			delete i;
			//			break;
			//		}
			//		case Destroyable:
			//		{
			//			cout << i->sprite.getPosition().x << "," << i->sprite.getPosition().y << " ";
			//			
			//			break;
			//		}
			//	}
			//}

		}
		/*float incrementor = 0.5f;
		for (int j = 0; j < enemies.size(); j++)
		{
			for (auto t : tile)
			{
				if (enemies[j]->sprite.getGlobalBounds().intersects(t->sprite.getGlobalBounds()))
				{
					incrementor = -incrementor;
				}
			}
				if (j%2)
				{
					enemies[j]->sprite.move(0.f, incrementor);

				}
				else
				{
					enemies[j]->sprite.move(incrementor, 0.f);
				}

			
		}*/

		if (touch)
		{
			switch (mytile)
			{
				case Enemy:
				{
					player.decreaseHp();
					player.viking.setPosition(vikingPrevPosition);
					break;
				}
				case Destroyable:
				{
					player.viking.setPosition(vikingPrevPosition);
					break;
				}
				case Border:
				{
					player.viking.setPosition(vikingPrevPosition);
					break;
				}
				case ExitUnlocked:
				{
					player.viking.setPosition(vikingPrevPosition);
					break;
				}
				case ExitLocked:
				{
					//bazi ba piroozy tamom she
				}
				case Power_life:
				{
					break;
				}
				case Power_Speed:
				{
					break;
				}
				case Power_StopEnemy:
				{
					break;
				}
				case Power_UnlimBombs:
				{
					break;
				}
				case Passable:
				{
					player.update();
					break;
				}
			}
		}
		else
		{
			player.update();
		}
		vikingPrevPosition = vikingPrev;
		

		



		//---------------------- renderer functions ------------------------
		window.clear();

		if (currentSate == MENU)
		{
			menu.draw(window);
		}
		else if (currentSate == OPTIONS_MENU) {
			optionMenu.draw(window);
		}
		else if (currentSate == PLAYING)
		{

			int elapsedTime = timerClock.getElapsedTime().asSeconds();
			int remainingTime = countdownDuration - elapsedTime;
			if (remainingTime > 0 && player.hp > 0)
			{
				sf::Texture LivesTexture;
				LivesTexture.loadFromFile("../Images/lives.png");
				sf::Sprite spriteLives;
				sf::Sprite spriteLives2;
				spriteLives.setTexture(LivesTexture);
				spriteLives2.setTexture(LivesTexture);
				if (player.hp > 0)
				{
					spriteLives.setPosition(515, Screen_height - 50.f);
					window.draw(spriteLives);
				}
				if (player.hp > 1)
				{
					spriteLives2.setPosition(455, Screen_height - 50.f);
					window.draw(spriteLives2);
				}



				int minutes = remainingTime / 60;
				int seconds = remainingTime % 60;


				sf::Font font;
				font.loadFromFile("../Images/absci___.ttf");

				sf::Text timerText;
				timerText.setFont(font);
				timerText.setCharacterSize(20);
				timerText.setFillColor(sf::Color::White);
				timerText.setPosition(250.f, Screen_height - 40.f);  // Adjust the position as needed

				/*int secondsRemaining = static_cast<int>(timerTime.asSeconds());
				std::string timerString = "Time: " + std::to_string(static_cast<int>(timerTime.asSeconds())) + "s";*/
				std::stringstream timerString;
				timerString << "Time: " << std::setw(2) << std::setfill('0') << minutes
					<< ":" << std::setw(2) << std::setfill('0') << seconds;
				timerText.setString(timerString.str());
				window.draw(timerText);






				for (auto t : tile)
				{
						window.draw(t->sprite);
				}

				window.draw(player.viking); //render the player

				for (int i = 0; i < bombIndex; i++) //render the bottom bombs
				{
					window.draw(dummyBomb.bombBar[i]);
				}

				for (auto& i : bombs) //render bombs on map
					window.draw(i->bomb);

				for (auto i : enemies) //render enemies on map
					window.draw(i->sprite);
			}
			else
			{
				window.clear();

				sf::Font font;
				font.loadFromFile("../Images/absci___.ttf");

				// Draw "GameOver" text or any other game over screen
				sf::Text gameOverText;
				gameOverText.setFont(font);
				gameOverText.setCharacterSize(50);
				gameOverText.setFillColor(sf::Color::Red);
				gameOverText.setPosition(Screen_width / 2.f, Screen_height / 2.f);
				gameOverText.setString("GameOver");

				// Draw the "GameOver" text
				window.draw(gameOverText);

				// Display the window content

				// Add any additional logic for handling GameOver, such as ending the game
				// You might want to break out of the main loop, show a score screen, etc.
			}
			
		}

		window.display();

	}
}
		
	


void loadMapTextures(
	Texture* border,
	Texture* passable,
	Texture* destructableBlock,
	Texture* exitLocked,
	Texture* exitUnlocked,
	Texture* powerLife,
	Texture* powerUnlimBomb,
	Texture* powerStopEnemy,
	Texture* powerSpeed,
	Texture* enemy)
{
	border->loadFromFile("../Images/InDestructable_Wall.png");
	destructableBlock->loadFromFile("../Images/Destructable_Wall.png");
	exitLocked->loadFromFile("../Images/Locked_Door.png");
	exitUnlocked->loadFromFile("../Images/Unlocked_Door.png");
	powerLife->loadFromFile("../Images/Add_life_power_2.png");
	powerUnlimBomb->loadFromFile("../Images/Unlimited_Bombs_power_1.png");
	powerStopEnemy->loadFromFile("../Images/Stop_Enemy_power_3.png");
	powerSpeed->loadFromFile("../Images/Increase_speed_power_4.png");
	enemy->loadFromFile("../Images/Enemy.png");
}

