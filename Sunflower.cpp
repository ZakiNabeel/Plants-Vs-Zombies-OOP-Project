#include "Sunflower.h"
Sunflower::Sunflower(int xPos, int yPos, int h, int w, int hit) : NonShooter(xPos, yPos, h, w, hit){}
Sunflower::~Sunflower() {}
void Sunflower::display() {}
void Sunflower::takeDamage()
{
	if (collisionCheck())
		this->hitPoints--;
}
bool Sunflower::collisionCheck()
{
	return collisionViaZombie();
}