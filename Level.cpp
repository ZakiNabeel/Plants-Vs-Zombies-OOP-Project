#include"Level.h"
Levels::Levels(int n):numZombies(n*5), zombieFactory(numZombies) {
}
void Levels::setNumZombies(int n) {
	this->numZombies = n * 5;
}
Levels::~Levels() {}

void Levels::display(sf::RenderWindow &Window) {
	zombieFactory.display(Window);
}

void Levels::update() {
	zombieFactory.updateZombies();
}
