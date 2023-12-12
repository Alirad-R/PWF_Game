#include "../header/OptionMenu.h"
#include "../header/Menu.h"

void OptionsMenu::DisplayHelp(sf::RenderWindow& window) {
    // Clear the window
    window.clear();

    // Create and configure a text object for displaying help information
    sf::Font font;
    if (!font.loadFromFile("../Images/absci___.ttf")) {
        // Handle error loading font
    }

    sf::Text helpText;
    sf::Text helpTextDestructable;
    sf::Text helpTextInDestructable;
    sf::Text helpTextLifePowerUp;
    sf::Text helpTextUnlimitedBombsPowerUp;
    sf::Text helpTextStopEnemyPowerUp;
    sf::Text helpTextSpeedPowerUp;
    sf::Text helpTextUnlockedDoor;
    sf::Text helpTextLockedDoor;
    sf::Text helpTextEnemy;
    helpText.setFont(font);
    helpText.setCharacterSize(20);
    helpText.setFillColor(sf::Color::White);
    helpText.setPosition(20.f, 20.f);  // Adjust the position as needed

    helpTextInDestructable.setFont(font);
    helpTextInDestructable.setCharacterSize(20);
    helpTextInDestructable.setFillColor(sf::Color::White);
    helpTextInDestructable.setPosition(80.f, 80.f);

    helpTextDestructable.setFont(font);
    helpTextDestructable.setCharacterSize(20);
    helpTextDestructable.setFillColor(sf::Color::White);
    helpTextDestructable.setPosition(80.f, 140.f);

    helpTextLifePowerUp.setFont(font);
    helpTextLifePowerUp.setCharacterSize(20);
    helpTextLifePowerUp.setFillColor(sf::Color::White);
    helpTextLifePowerUp.setPosition(80.f, 200.f);

    helpTextUnlimitedBombsPowerUp.setFont(font);
    helpTextUnlimitedBombsPowerUp.setCharacterSize(20);
    helpTextUnlimitedBombsPowerUp.setFillColor(sf::Color::White);
    helpTextUnlimitedBombsPowerUp.setPosition(80.f, 260.f);

    helpTextStopEnemyPowerUp.setFont(font);
    helpTextStopEnemyPowerUp.setCharacterSize(20);
    helpTextStopEnemyPowerUp.setFillColor(sf::Color::White);
    helpTextStopEnemyPowerUp.setPosition(80.f, 320.f);

    helpTextSpeedPowerUp.setFont(font);
    helpTextSpeedPowerUp.setCharacterSize(20);
    helpTextSpeedPowerUp.setFillColor(sf::Color::White);
    helpTextSpeedPowerUp.setPosition(80.f, 380.f);

    helpTextUnlockedDoor.setFont(font);
    helpTextUnlockedDoor.setCharacterSize(20);
    helpTextUnlockedDoor.setFillColor(sf::Color::White);
    helpTextUnlockedDoor.setPosition(80.f, 440.f);

    helpTextLockedDoor.setFont(font);
    helpTextLockedDoor.setCharacterSize(20);
    helpTextLockedDoor.setFillColor(sf::Color::White);
    helpTextLockedDoor.setPosition(80.f, 500.f);

    helpTextEnemy.setFont(font);
    helpTextEnemy.setCharacterSize(20);
    helpTextEnemy.setFillColor(sf::Color::White);
    helpTextEnemy.setPosition(80.f, 560.f);

    // Display help information
    std::string helpInfo = "Help Information:\n";
    helpInfo += "-----------------\n";
    std::string helpTextInDestructableInfo = "InDestructable Block: cannot be destroyed.";
    std::string helpTextDestructableInfo = "Destructable Block: can be destroyed.";
    std::string helpTextLifePowerUpInfo = "Add life power up: adds one life (max 2 lives).";
    std::string helpTextUnlimitedBombsPowerUpInfo = "Unlimited bombs power up: plant bombs without limit for\n";
    helpTextUnlimitedBombsPowerUpInfo += "10 seconds.";
    std::string helpTextStopEnemyPowerUpInfo = "Stop Enemy power up: stops the enemies for 10 seconds.";
    std::string helpTextSpeedPowerUpInfo = "Speed power up: doubles your speed for the rest of the\n";
    helpTextSpeedPowerUpInfo += "game.";
    std::string helpTextUnlockedDoorInfo = "Locked door Block: the door is locked.";
    std::string helpTextLockedDoorInfo = "Locked door Block: the door is locked.";
    std::string helpTextEnemyInfo = "Enemy Block: represents the enemies.";
    //helpInfo += "InDestructable Block: cannot be destroyed.\n";
    /*helpInfo += "Destructable Block: can be destroyed.\n";
    helpInfo += "Add life power up: adds one life (max 2 lives).\n";
    helpInfo += "Unlimited bombs power up: plant bombs without limit for 10 seconds.\n";
    helpInfo += "Stop Enemy power up: stops the enemies for 10 seconds.\n";
    helpInfo += "Speed power up: doubles your speed for the rest of the game.\n";
    helpInfo += "Unlocked door Block: the door is unlocked.\n";
    helpInfo += "Locked door Block: the door is locked.\n";
    helpInfo += "Enemy Block: represents the enemies.\n";*/
    // Add information for other block types and power-ups

    helpText.setString(helpInfo);
    helpTextInDestructable.setString(helpTextInDestructableInfo);
    helpTextDestructable.setString(helpTextDestructableInfo);
    helpTextLifePowerUp.setString(helpTextLifePowerUpInfo);
    helpTextUnlimitedBombsPowerUp.setString(helpTextUnlimitedBombsPowerUpInfo);
    helpTextStopEnemyPowerUp.setString(helpTextStopEnemyPowerUpInfo);
    helpTextSpeedPowerUp.setString(helpTextSpeedPowerUpInfo);
    helpTextUnlockedDoor.setString(helpTextUnlockedDoorInfo);
    helpTextLockedDoor.setString(helpTextLockedDoorInfo);
    helpTextEnemy.setString(helpTextEnemyInfo);
    // Draw the help text on the window
    window.draw(helpText);
    window.draw(helpTextInDestructable);
    window.draw(helpTextDestructable);
    window.draw(helpTextLifePowerUp);
    window.draw(helpTextUnlimitedBombsPowerUp);
    window.draw(helpTextStopEnemyPowerUp);
    window.draw(helpTextSpeedPowerUp);
    window.draw(helpTextUnlockedDoor);
    window.draw(helpTextLockedDoor);
    window.draw(helpTextEnemy);

    sf::Sprite spriteInDestructable(textureInDestructable);
    spriteInDestructable.setPosition(20.f, 80.f);
    window.draw(spriteInDestructable);

    sf::Sprite spriteTextDestructable(textureDestructable);
    spriteTextDestructable.setPosition(20.f, 140.f);
    window.draw(spriteTextDestructable);

    sf::Sprite spriteTextLifePowerUp(textureAddLife);
    spriteTextLifePowerUp.setPosition(20.f, 200.f);
    window.draw(spriteTextLifePowerUp);

    sf::Sprite spriteTextUnlimitedBombsPowerUp(textureUnlimitedBombs);
    spriteTextUnlimitedBombsPowerUp.setPosition(20.f, 260.f);
    window.draw(spriteTextUnlimitedBombsPowerUp);

    sf::Sprite spriteTextStopEnemyPowerUp(textureStopEnemy);
    spriteTextStopEnemyPowerUp.setPosition(20.f, 320.f);
    window.draw(spriteTextStopEnemyPowerUp);

    sf::Sprite spriteTextSpeedPowerUp(textureSpeed);
    spriteTextSpeedPowerUp.setPosition(20.f, 380.f);
    window.draw(spriteTextSpeedPowerUp);

    sf::Sprite spriteTextUnlockedDoor(textureUnlockedDoor);
    spriteTextUnlockedDoor.setPosition(20.f, 440.f);
    window.draw(spriteTextUnlockedDoor);

    sf::Sprite spriteTextLockedDoor(textureLockedDoor);
    spriteTextLockedDoor.setPosition(20.f, 500.f);
    window.draw(spriteTextLockedDoor);

    sf::Sprite spriteTextEnemy(textureEnemy);
    spriteTextEnemy.setPosition(20.f, 560.f);
    window.draw(spriteTextEnemy);


    // Display the window content
    window.display();

    sf::Event event;
    while (window.waitEvent(event))
    {
        if (event.type == sf::Event::KeyPressed)
        {
            break;
        }
    }
}

void OptionsMenu::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 2; i++)
    {
        window.draw(menu[i]);
    }
}
