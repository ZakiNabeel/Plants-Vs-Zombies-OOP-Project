#include "Repeater.h"
Repeater::Repeater(int xPos, int yPos, int h, int w, int hit) : Shooter(xPos, yPos, h, w, hit) {}
Repeater::~Repeater() {}
void Repeater::display() {}
void Repeater::takeDamage()
{
	if (collisionCheck())
		this->hitPoints--;
}
bool Repeater::collisionCheck()
{
	return collisionViaZombie();
}