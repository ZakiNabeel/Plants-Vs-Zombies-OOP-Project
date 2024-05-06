#include "NonShooter.h"
NonShooter::NonShooter(int xPos, int yPos, int h, int w, int hp) : Plants(xPos, yPos, h, w, hp) {
	cout << "NonShooter constructor" << endl;
}
NonShooter::~NonShooter() {}
void NonShooter::display(sf::RenderWindow & Window) {
	cout << " ";
	cout << "Display non shooter" << endl;
}
bool NonShooter::collisionCheck()
{
	cout << "WalkNut collide";
	return 1;
}
void NonShooter::takeDamage()
{	
	cout << "WalkNut hit" << endl;
	this->hitPoints--;
}
void NonShooter::magic()
{
	cout << "nonShooter magic" << endl;
}
