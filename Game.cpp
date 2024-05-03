#include"Game.h"
//Drawing the background
Game::Game() :levelNumber(1), level(new BeginersGarden()){
}
Game::~Game() {
	delete [] level;
}
void Game::run() {
	//Create a window, n*n
	//DancingZombies dancer(1100, 300, 1, 1, 1, 1);
	
	sf::RenderWindow window(sf::VideoMode(1400, 600), "Plants Vs Zombies");
	window.setFramerateLimit(144);
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
			window.clear();
			level->createBack(window);
			level->update();
			level->display(window);
			window.setSize(sf::Vector2u(1200, 650));
			window.display();
		}
	}
}