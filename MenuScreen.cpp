#include "MenuScreen.h"
#include <iostream>
MenuScreen::MenuScreen() : Screen("D:\\Visual Studio\\ProjectPVZ\\ProjectPVZ\\background menu.png"), 
playButton("Play", 150, 50, 700 - 75, 150), // Centered X, higher Y
scoreboardButton("Scoreboard", 150, 50, 700 - 75, 220), // Same X, slightly lower Y
instructionsButton("Instructions", 150, 50, 700 - 75, 290) {}
void MenuScreen::draw(sf::RenderWindow& window)
{
	window.draw(screenSprite);
	playButton.draw(window);
	scoreboardButton.draw(window);
	instructionsButton.draw(window);
}
bool MenuScreen::update(sf::RenderWindow& window, sf::Event& event) {
    if (playButton.wasClicked(window, event)) {
        std::cout << "Play button was clicked." << std::endl;
        return true; // Play button was clicked
    }
    return false; // No action taken
}
Button& MenuScreen::getPlayButton()
{
    return playButton;
}