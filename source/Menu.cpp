#include "../header/Menu.h"

Menu::Menu(float width, float height) {
	if (!font.loadFromFile("../Images/absci___.ttf"))
	{
		//handle error
	}

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Options");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	selectedItemIndex = 0;
}

void Menu::draw(sf::RenderWindow &window) {
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp() {
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown() {
	if (selectedItemIndex - 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

//void Menu::OptionPressed() {
//	sf::Text help;
//	help.setFont(font);
//	help.setFillColor(sf::Color::White);
//	help.setString("This is for your help");
//}

//void Menu::updateMenuSize(float width, float height) {
//	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
//		menu[i].setPosition(sf::Vector2f(width / 2 , height / (MAX_NUMBER_OF_ITEMS + 1) * (i + 1)));
//		menu[i].setCharacterSize(10);
//	}
//}

Menu::~Menu() {

}