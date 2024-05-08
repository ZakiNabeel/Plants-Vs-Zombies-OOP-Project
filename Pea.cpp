#include"Pea.h"
Pea::Pea(int xPos, int yPos, int h, int w, int hit, int s = 1) : Moving(xPos, yPos, h, w, hit, s) {
	this->isPresent = 0;
}
Pea::~Pea(){}
void Pea::display(sf::RenderWindow & Window){
	cout << "abs";
}
void Pea::movement() {
	movementRight();
	cout << "cnuw";
}
void Pea::collisionCheck(Zombie**& zombieEntities, int size) {
	cout << "Pea collision check";
	for (int i = 0; i < size; i++) {
		if (zombieEntities[i]->position.getX() == position.getX() && zombieEntities[i]->position.getY() == position.getY()) {
			zombieEntities[i]->takeDamage();
			isPresent = 0;
		}
	}
}
void Pea::takeDamage() {
	cout << "Peacsssssssssssss";
}
void Pea::setX(int x) {
	position.setX(x);
}
void Pea::setY(int y) {
	position.setY(y);
}
void Pea::setH(int h) {
	size.setHeight(h);
}
void Pea::setW(int w) {
	size.setWidth(w);
}
void Pea::setHit(int hit) {
	hitPoints = hit;
}
void Pea::setSpeed(int s) {
	speed = s;
}
