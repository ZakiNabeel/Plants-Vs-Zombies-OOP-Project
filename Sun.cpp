#include"Sun.h"
Sun::Sun(int xPos, int yPos, int h, int w, int hit, int s = 1) : Moving(xPos, yPos, h, w, hit, s) {}
Sun::~Sun(){}
void Sun::display(){}
void Sun::movement() {
	Sun::movementVertical();
}
