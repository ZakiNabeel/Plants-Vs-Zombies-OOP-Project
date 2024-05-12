// DolphinRiderZombies.cpp
#include "DolphinRiderZombies.h"

DolphinRiderZombies::DolphinRiderZombies(int xPos, int yPos, int h, int w, int hit, int s) : Zombie(xPos, yPos, h, w, hit, s) {
	spriteEntity.texture.loadFromFile("DolphinZombie_.png");
	sf::IntRect rectSourceSprite(0, 0, 16, 16);
	spriteEntity.sprite.setTexture(spriteEntity.texture);
	spriteEntity.sprite.setTextureRect(rectSourceSprite);
	spriteEntity.sprite.setScale(5.0f, 6.0f);
	NorthWest = false;
	SouthWest = false;
	typeDancer = 0;
	right = 1;
}

DolphinRiderZombies::~DolphinRiderZombies() {}

void DolphinRiderZombies::movement() {
	movementLeft();
	spriteEntity.sprite.setPosition(position.getX(), position.getY());
//	cout << "Moved Dolphin" << endl;
}

void DolphinRiderZombies::takeDamage() {
	hitPoints -= 3;
}

void DolphinRiderZombies::display(sf::RenderWindow& Window) {
	Window.draw(spriteEntity.sprite);
	//cout << "DolphinRiderZombies Displayed" << endl;
}


void DolphinRiderZombies::collisionCheck(Plants** & plantEntites, int size) {
	cout << "Collision Check Dolphin Zombie" << endl;
}
