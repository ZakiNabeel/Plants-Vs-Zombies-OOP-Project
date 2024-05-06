#include "Plants.h"
Plants::Plants(int xPos, int yPos, int h, int w, int hp) : Entity(xPos, yPos, h, w, hp) {
	cout << "Plants constructor" << endl;
}
Plants::~Plants() {}
void Plants::takeDamage() {
	cout << "Take damage plants" << endl;
}
void Plants::display(sf::RenderWindow& Window) {
	cout << "display plants" << endl;
}
bool Plants::collisionCheck() {
	cout << "collision check plants" << endl;
	return 1;
}		