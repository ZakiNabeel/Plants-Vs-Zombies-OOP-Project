#include"LawnMover.h"
LawnMover::LawnMover(int xPos, int yPos, int h, int w, int hit, int s = 1) : Moving(xPos, yPos, h, w, hit, s) {
	isPresent = 1;

}
LawnMover::~LawnMover(){}
void LawnMover::display(){}
void LawnMover::movement() {
	movementRight();
}
void LawnMover::collisionCheck(Zombie ** & zombieEntities, int size) {
	for (int i = 0; i < size; i++) {
		if (zombieEntities[i]->position.getX() == position.getX() && zombieEntities[i]->position.getY() == position.getY()) {
			zombieEntities[i]->takeDamage();
			isPresent = 0;
		}
	}
}