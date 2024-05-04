#include "Shooter.h"
Shooter::Shooter(int xPos, int yPos, int h, int w, int hp) : Plants(xPos, yPos, h, w, hp) {}
Shooter::~Shooter() {}
bool Shooter::collisionCheck()
{
	return collisionViaZombie();
}
void Shooter::display() {}
void Shooter::takeDamage()
{
	if (collisionCheck())
		this->hitPoints--;
}