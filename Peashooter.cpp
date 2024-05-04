#include "Peashooter.h"
#include "SFML/Graphics.hpp"
using namespace sf;
Peashooter::Peashooter(int xPos, int yPos, int h, int w, int hit) : Shooter(xPos, yPos, h, w, hit) {}
Peashooter::~Peashooter() {}
void Peashooter::takeDamage()
{
	if (collisionCheck())
		this->hitPoints--;
}
void Peashooter::display() {}
bool Peashooter::collisionCheck()
{
	return collisionViaZombie();
}