#include "Lillypad.h"
Lillypad::Lillypad(int xPos, int yPos, int h, int w, int hp) : Entity(xPos, yPos, h, w, hp) {}
Lillypad::~Lillypad() {}
void Lillypad::display() {}
bool Lillypad::collisionCheck()
{
	return collisionViaPlant();
}