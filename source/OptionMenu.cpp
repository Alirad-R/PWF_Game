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
    helpText.setFont(font);
    helpText.setCharacterSize(20);
    helpText.setFillColor(sf::Color::White);
    helpText.setPosition(20.f, 20.f);  // Adjust the position as needed

    // Display help information
    std::string helpInfo = "Help Information:\n";
    helpInfo += "-----------------\n";
    helpInfo += "InDestructable Block: This block cannot be destroyed.\n";
    helpInfo += "Destructable Block: This block can be destroyed.\n";
    helpInfo += "Add life power up: This block adds one life (max 2 lives).\n";
    helpInfo += "Unlimited bombs power up: This block lets you plant bombs without limit for 10 seconds.\n";
    helpInfo += "Stop Enemy power up: This block stops the enemies for 10 seconds.\n";
    helpInfo += "Speed power up: This block doubles your speed for the rest of the game.\n";
    helpInfo += "Unlocked door Block: This block shows that the door is unlocked.\n";
    helpInfo += "Locked door Block: This block shows that the door is locked.\n";
    helpInfo += "Enemy Block: This block represents the enemies.\n";
    // Add information for other block types and power-ups

    helpText.setString(helpInfo);

    // Draw the help text on the window
    window.draw(helpText);

    // Display the window content
    window.display();
}

void OptionsMenu::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 2; i++)
    {
        window.draw(menu[i]);
    }
}
