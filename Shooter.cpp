#include "Shooter.h"
Shooter::Shooter(int xPos, int yPos, int h, int w, int hp) : Plants(xPos, yPos, h, w, hp) {
	peaPtr = nullptr;
}
Shooter::~Shooter() {
	delete[] peaPtr;
}
bool Shooter::collisionCheck()
{
	return collisionViaZombie();
}
void Shooter::display(sf::RenderWindow & Window) {}

void Shooter::takeDamage()
{
	if (collisionCheck())
		this->hitPoints--;
}

void Shooter::magic() {
	cout << "Magic shooter" << endl;
}
