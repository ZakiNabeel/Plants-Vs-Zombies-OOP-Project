#include "NonShooter.h"
NonShooter::NonShooter(int xPos, int yPos, int h, int w, int hp) : Plants(xPos, yPos, h, w, hp) {}
NonShooter::~NonShooter() {}
void NonShooter::display() {}
bool NonShooter::collisionCheck()
{
	return collisionViaZombie();
}
void NonShooter::takeDamage()
{
	if (collisionCheck())
		this->hitPoints--;
}