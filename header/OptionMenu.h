#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../header/Menu.h"
class OptionsMenu : public Menu {
public:
    OptionsMenu(float width, float height) : Menu(width, height) {
        menu[0].setString("Help");
        menu[1].setString("Back");
    }
    void DisplayHelp(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

private:
    // Add any additional data members as needed for your options menu
};

