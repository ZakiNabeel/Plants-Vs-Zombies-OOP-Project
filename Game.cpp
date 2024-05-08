#include"Game.h"
#include"Zombie.h"
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
//	window.setFramerateLimit(144);
	sf::Event event;
	sf::Clock clock;
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
				level->updatePlantFactory(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y,1,1,1);
				plantClicked = 0;
			}	
			window.clear();
			level->createBack(window);
			window.draw(grid);
			level->update();
			level->display(window);
			window.setSize(sf::Vector2u(1400, 600));
			window.display();
		}
	}
}