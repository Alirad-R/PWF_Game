#include <iostream>
#include "../header/Player.h"
#include <SFML/Graphics.hpp>
using namespace std;

int main() {

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
		window.display();
	}
}