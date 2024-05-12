#include"Game.h"
#include"Zombie.h"
#include<SFML/Audio.hpp>
//Drawing the background
Game::Game() :levelNumber(1),totalLevels(2),coins(500){
	level = new Levels * [totalLevels];
	level[0] = new BeginersGarden();
	level[1] = new ZombieOutskirts();
	plantClicked = 0; 
	sunPtr = nullptr;
	this-> newLevelCheck=0; 
	lives = 1;
	levelNumber++;
}
Game::~Game() {
	for (int i = 0; i < totalLevels; i++) {
		delete level[i];
	}
	delete [] level;
}
void Game::newLevel() {
	if (levelNumber <= totalLevels) {
		cout << "Hello" << endl;
		//delete level[levelNumber - 1];
		//cout << "Hello" << endl;
		levelNumber++;
		level[levelNumber] = new ZombieOutskirts();
		cout << "Hello" << endl;
	}
}


int Game::getLevelNumber() {
	return this->levelNumber;
}
void Game::run() {
	sf::RenderWindow window(sf::VideoMode(1400, 600), "Plants Vs Zombies");
//	window.setFramerateLimit(144);
	sf::Event event;
	sf::Clock clock;
	sf::Clock sunClock;
	sf::Font fontScore;
	fontScore.loadFromFile("KnightWarrior-w16n8.otf");
	sf::Text textScore;
	textScore.setFont(fontScore);
	textScore.setCharacterSize(40);
	textScore.setFillColor(sf::Color::Red);
	textScore.setPosition(1200, 0); 
	textScore.setString("Coins: " + to_string(coins));
	sf::SoundBuffer music;
	music.loadFromFile("Peritune_Crimson_Moon-chosic.com_.mp3"); 
	while (window.isOpen())
	{
		cout << "LEVEL NUMBER ============================ " << levelNumber << endl;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && plantClicked==0)
			{
				cout << "MOUSE CLICKED!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!LESGOO" << endl;
				plantClicked=level[levelNumber - 1]->checkMouseClick(window, sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && plantClicked == 1) {
				cout << "DAN DANA DAN DAN DANA DAN DAN" << endl;
				level[levelNumber - 1]->updatePlantFactory(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, 1, 1, 1, coins);
 				plantClicked = 0;
				textScore.setString("Coins: " + to_string(coins));
			}	
			if (sunClock.getElapsedTime().asSeconds() >= 15) {
				sunGenerated = 1;
			}
			if (sunGenerated == 1) {
				sunPtr = new Sun(((rand()%10)+2)*100, 0, 1, 1, 0, 1);
				sunGenerated = 0;
				coins += 100;
				sunClock.restart();
			}
			window.clear();
			level[levelNumber-1]->createBack(window);
			window.draw(grid);
			level[levelNumber - 1]->update(coins);
			textScore.setString("Coins: " + to_string(coins));
			level[levelNumber - 1]->display(window);
			window.draw(textScore);
			if (sunPtr != nullptr) {
				sunPtr->movement();
				sunPtr->display(window);
			}
			if (level[levelNumber - 1]->checkZombieWin(level[levelNumber - 1]->getZombieFactory().getZombiePtr(), level[levelNumber - 1]->getZombieFactory().getSize(), lives)) {
				window.close();
			}
			window.setSize(sf::Vector2u(1400, 600));
			window.display();
			if (!level[levelNumber - 1]->checkNewWave(levelNumber)) {
				levelNumber++;
				cout << "Done" << levelNumber << endl;
			}

	}
}