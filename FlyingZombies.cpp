// FlyingZombies.cpp
#include "FlyingZombies.h"

FlyingZombies::FlyingZombies(int xPos, int yPos, int h, int w, int hit, int s) : Zombie(xPos, yPos, h, w, hit, s) {
	spriteEntity.texture.loadFromFile("BaloonZombie_.png");
	sf::IntRect rectSourceSprite(0, 0, 35, 57);
	spriteEntity.sprite.setTexture(spriteEntity.texture);
	spriteEntity.sprite.setTextureRect(rectSourceSprite);
	spriteEntity.sprite.setScale(2.2f, 1.9f);
}

FlyingZombies::~FlyingZombies() {}

void FlyingZombies::movement() {
	movementLeft();
	spriteEntity.sprite.setPosition(position.getX(), position.getY());
}

void FlyingZombies::takeDamage() {
	hitPoints -= 4;
}

void FlyingZombies::display(sf::RenderWindow& Window) {
	Window.draw(spriteEntity.sprite);
//	cout << "FlyingZombies Displayed" << endl;
}

bool FlyingZombies::collisionCheck() { return 1; }
