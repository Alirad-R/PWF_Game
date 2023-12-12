#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../header/Menu.h"
class OptionsMenu : public Menu {
public:
    OptionsMenu(float width, float height) : Menu(width, height) {
        menu[0].setString("View Blocks");
        menu[1].setString("Back");
        textureInDestructable.loadFromFile("../Images/InDestructable_Wall.png");
        textureDestructable.loadFromFile("../Images/Destructable_Wall.png");
        textureAddLife.loadFromFile("../Images/Add_life_power_2.png");
        textureUnlimitedBombs.loadFromFile("../Images/Unlimited_Bombs_power_1.png");
        textureStopEnemy.loadFromFile("../Images/Stop_Enemy_power_3.png");
        textureSpeed.loadFromFile("../Images/Increase_speed_power_4.png");
        textureUnlockedDoor.loadFromFile("../Images/Unlocked_Door.png");
        textureLockedDoor.loadFromFile("../Images/Locked_Door.png");
        textureEnemy.loadFromFile("../Images/Enemy.png");
    }
    void DisplayHelp(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

private:
    sf::Texture textureInDestructable;
    sf::Texture textureDestructable;
    sf::Texture textureAddLife;
    sf::Texture textureUnlimitedBombs;
    sf::Texture textureStopEnemy;
    sf::Texture textureSpeed;
    sf::Texture textureUnlockedDoor;
    sf::Texture textureLockedDoor;
    sf::Texture textureEnemy;
};

