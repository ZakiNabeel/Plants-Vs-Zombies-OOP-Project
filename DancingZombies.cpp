// DancingZombies.cpp
#include "DancingZombies.h"

DancingZombies::DancingZombies(int xPos, int yPos, int h, int w, int hit, int s) : Zombie(xPos, yPos, h, w, hit, s) {
	spriteEntity.texture.loadFromFile("Zombies/DancingZombie1.png");
	sf::IntRect rectSourceSprite(0, 0, 50, 50);
	spriteEntity.sprite.setTexture(spriteEntity.texture);
	spriteEntity.sprite.setPosition(xPos, yPos);
}

DancingZombies::~DancingZombies() {}

void DancingZombies::movement() {
    Moving::movementLeft();
//	cout << "Moved" << endl;
}

void DancingZombies::takeDamage() {
    hitPoints -= 2;
}

void DancingZombies::display(sf::RenderWindow & Window) {
    Window.draw(spriteEntity.sprite);
//	cout << "DancingZombies Displayed" << endl;
}

void DancingZombies::collisionCheck(Plants** & plantEntites, int size) {
	cout << "Collision Check Dancing Zombie" << endl;
}
