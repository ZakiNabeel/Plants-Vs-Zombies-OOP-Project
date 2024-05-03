// FootballZombies.cpp
#include "FootballZombies.h"

FootballZombies::FootballZombies(int xPos, int yPos, int h, int w, int hit, int s) : Zombie(xPos, yPos, h, w, hit, s) {
	spriteEntity.texture.loadFromFile("FootballZombie_.png");
	sf::IntRect rectSourceSprite(0, 0, 40, 50);
	spriteEntity.sprite.setTexture(spriteEntity.texture);
	spriteEntity.sprite.setTextureRect(rectSourceSprite);
	spriteEntity.sprite.setScale(1.75f, 1.75f);
}

FootballZombies::~FootballZombies() {}

void FootballZombies::movement() {
	movementLeft();
	spriteEntity.sprite.setPosition(position.getX(), position.getY());
}

void FootballZombies::takeDamage() {
	hitPoints -= 5;
}

void FootballZombies::display(sf::RenderWindow& Window) {
	Window.draw(spriteEntity.sprite);
	cout << "FootballZombies Displayed" << endl; 
}

bool FootballZombies::collisionCheck() { return 1; }
