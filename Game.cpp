#include"Game.h"
//Drawing the background
Game::Game() :levelNumber(1), level(new BeginersGarden()), screens(new MenuScreen()){
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
    //	window.setFramerateLimit(144);
    sf::Event event;
    sf::Clock clock;
    bool gameStarted = false;  // Flag to track if the game has started

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Here, check if the play button in the menu screen was clicked
            if (!gameStarted && event.type == sf::Event::MouseButtonReleased) {
                // Ensure we're dealing with the left mouse button
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Safely cast screens to MenuScreen and check the button click
                    MenuScreen* menuScreen = dynamic_cast<MenuScreen*>(screens);
                    if (menuScreen && menuScreen->getPlayButton().wasClicked(window, event)) {
                        gameStarted = true;  // Set the game to start
                        levelNumber = 1;  // Optionally set which level to start
                    }
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
        else {
            // If the game has not started, draw the menu screen
            screens->draw(window);
        }
        window.setSize(sf::Vector2u(1400, 600));
        window.display();
    }
}

