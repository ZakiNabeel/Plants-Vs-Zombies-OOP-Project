#include "Plants.h"
Plants::Plants(int xPos, int yPos, int h, int w, int hp) : Entity(xPos, yPos, h, w, hp) {}
Plants::~Plants() {}
bool Plants::collisionCheck()
{
	if (collisionViaPlant())
		return true;
	if (collisionViaZombie())
		return true;
	return false;
}