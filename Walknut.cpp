#include "Walknut.h"
Walknut::Walknut(int xPos, int yPos, int h, int w, int hit) : NonShooter(xPos, yPos, h, w, hit) {}
Walknut::~Walknut() {}
void Walknut::takeDamage()
{
	if (collisionCheck())
		this->hitPoints--;
}
void Walknut::display() {}
bool Walknut::collisionCheck()
{
	return collisionViaZombie();
}