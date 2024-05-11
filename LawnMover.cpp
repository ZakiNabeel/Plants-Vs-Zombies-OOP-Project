#include"LawnMover.h"
LawnMover::LawnMover(int xPos, int yPos, int h, int w, int hit, int s = 1) : Moving(xPos, yPos, h, w, hit, s) {}
LawnMover::~LawnMover(){}
void LawnMover::display(){}
void LawnMover::movement() {
	movementRight();
}
bool LawnMover::collisionCheck() {
	collisionViaZombie();
	return 1;
}