#include "Cherrybomb.h"
Cherrybomb::Cherrybomb(int xPos, int yPos, int h, int w, int hp) : NonShooter(xPos, yPos, h, w, hp) {}
Cherrybomb::~Cherrybomb() {}
void Cherrybomb::display() {}
void Cherrybomb::movement() {}
void Cherrybomb::takeDamage()
{
	if (collisionCheck())
		this->hitPoints = 0;
}
bool Cherrybomb::collisionCheck()
{
	return collisionViaZombie();
}