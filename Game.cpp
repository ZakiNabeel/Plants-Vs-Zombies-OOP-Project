#include"Game.h"
#include"Zombie.h"
//Drawing the background
Game::Game() :levelNumber(1),coins(500), level(new BeginersGarden()){
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
	sf::Font fontScore;
	fontScore.loadFromFile("KnightWarrior-w16n8.otf");
	sf::Text textScore;
	textScore.setFont(fontScore);
	textScore.setCharacterSize(40);
	textScore.setFillColor(sf::Color::Red);
	textScore.setPosition(1200, 0);
	textScore.setString("Coins: " + to_string(coins));
	while (window.isOpen())
	{
		if (levelNumber == 1) {
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && plantClicked==0)
			{
				cout << "MOUSE CLICKED!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!LESGOO" << endl;
				plantClicked=level->checkMouseClick(window, sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && plantClicked == 1) {
				cout << "DAN DANA DAN DAN DANA DAN DAN" << endl;
				level->updatePlantFactory(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y,1,1,1,coins);
 				plantClicked = 0;
				textScore.setString("Coins: " + to_string(coins));
			}	
			window.clear();
			level->createBack(window);
			window.draw(grid);
			level->update(coins);
			textScore.setString("Coins: " + to_string(coins));
			level->display(window);
			window.draw(textScore);
			window.setSize(sf::Vector2u(1400, 600));
			window.display();
		}
	}
}