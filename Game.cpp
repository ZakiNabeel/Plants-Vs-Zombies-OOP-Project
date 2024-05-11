#include"Game.h"
//Drawing the background
Game::Game() :levelNumber(1), level(new BeginersGarden()){
	grid.setSize(sf::Vector2f(750, 500));
	grid.setPosition(250, 80);
	grid.setFillColor(sf::Color::Transparent);
	grid.setOutlineColor(sf::Color::Black);
	grid.setOutlineThickness(2);
	plantClicked = 0;
}
Game::~Game() {
	delete [] level;
}
int Game::getLevelNumber() {
	return this->levelNumber;
}
void Game::run() {
    sf::RenderWindow window(sf::VideoMode(1400, 600), "Plants Vs Zombies");
    sf::Event event;
    bool gameStarted = false;
    bool instructionSelected = false;

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (!gameStarted && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                if (!instructionSelected) {
                    if (menuScreen.getPlayButton().wasClicked(window, event)) {
                        gameStarted = true;  // Start the game
                    }
                    else if (menuScreen.getInstructionButton().wasClicked(window, event)) {
                        instructionSelected = true;  // Display instructions
                    }
                }
                else if (instructionScreen.getBackButton().wasClicked(window, event)) {
                    instructionSelected = false;  // Go back to menu
                }
            }
        }

        window.clear();
        if (gameStarted) {
            // The game level should be active only if gameStarted is true
            if (levelNumber == 1) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && plantClicked == 0) {
                    cout << "MOUSE CLICKED!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!LESGOO" << endl;
                    plantClicked = level->checkMouseClick(window, sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && plantClicked == 1) {
                    cout << "DAN DANA DAN DAN DANA DAN DAN" << endl;
                    level->getPlantFactory().addPlant(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, 1, 1, 1);
                    plantClicked = 0;
                }
                level->createBack(window);
                level->update();
                level->display(window);
            }
        }
        if (gameStarted) {
            // Game logic here
        }
        else if (instructionSelected) {
            instructionScreen.draw(window);
        }
        else {
            menuScreen.draw(window);
        }
        window.display();
    }
}
