#include"Moving.h"
Moving::Moving(int xPos, int yPos, int h, int w, int hit,int s):Entity(xPos,yPos,h,w,hit){
	this->speed = s;
}
Moving::~Moving(){}
int Moving::getSpeed() {
	return this->speed;
}
void Moving::movementLeft() {
	position.setX((position.getX() - this->speed));
	spriteEntity.sprite.setPosition(position.getX(), position.getY());
}
void Moving::movementRight() {
	position.setX((int)(position.getX() + this->speed));
	spriteEntity.sprite.setPosition(position.getX(), position.getY());
}
void Moving::movementVertical() {
	position.setY((int)(position.getY() + this->speed));
	spriteEntity.sprite.setPosition(position.getX(), position.getY());
}
void Moving::movementDiagonal() {
	position.setY((int)(position.getY() + this->speed));
	position.setX((int)(position.getX() + this->speed));
	spriteEntity.sprite.setPosition(position.getX(), position.getY());
}
