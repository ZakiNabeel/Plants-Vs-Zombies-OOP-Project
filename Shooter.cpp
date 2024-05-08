#include "Shooter.h"
Shooter::Shooter(int xPos, int yPos, int h, int w, int hp) : Plants(xPos, yPos, h, w, hp) {
	peaPtr = nullptr;
}
Shooter::~Shooter() {
	delete[] peaPtr;
}
void Shooter::collisionCheck(Zombie ** &zombieEntities, int size)
{
	cout<<"Coliision Check Shooter"<<endl;
}
void Shooter::display(sf::RenderWindow & Window) {}

void Shooter::takeDamage()
{
		this->hitPoints--;
}

void Shooter::magic() {
	cout << "Magic shooter" << endl;
}
