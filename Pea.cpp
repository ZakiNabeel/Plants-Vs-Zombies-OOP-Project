#include"Pea.h"
Pea::Pea(int xPos, int yPos, int h, int w, int hit, int s = 1) : Moving(xPos, yPos, h, w, hit, s) {}
Pea::~Pea(){}
void Pea::display(){}
void Pea::movement() {
	movementRight();
}
bool Pea::collisionCheck() {
	collisionViaZombie();
	return 1;
}