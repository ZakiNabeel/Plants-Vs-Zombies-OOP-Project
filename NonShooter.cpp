#include "NonShooter.h"
NonShooter::NonShooter(int xPos, int yPos, int h, int w, int hp) : Plants(xPos, yPos, h, w, hp) {
	cout << "NonShooter constructor" << endl;
}
NonShooter::~NonShooter() {}
void NonShooter::display(sf::RenderWindow & Window) {
	cout << " ";
	cout << "Display non shooter" << endl;
}
void NonShooter::collisionCheck(Zombie ** &zombieEntities, int size)
{
	cout << "Coliision checkk non shooter" << endl;

}
void NonShooter::magic()
{
	cout << "nonShooter magic" << endl;
}
