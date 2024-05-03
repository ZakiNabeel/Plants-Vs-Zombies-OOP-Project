#include"WhitePea.h"
WhitePea::WhitePea(int xPos, int yPos, int h, int w, int hit, int s = 1) : Pea(xPos, yPos, h, w, hit, s) {}
WhitePea::~WhitePea(){}
void WhitePea::display(){}
void WhitePea::movement() {
	movementRight();
}
bool WhitePea::collisionCheck() {
	collisionViaZombie();
	return 1;
}