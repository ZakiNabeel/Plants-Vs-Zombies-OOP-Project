#include "Repeater.h"
Repeater::Repeater(int xPos, int yPos, int h, int w, int hit) : Shooter(xPos, yPos, h, w, hit) {
	spriteEntity.texture.loadFromFile("Repeater.png");
	sf::IntRect rectSourceSprite(0, 0, 35, 35);
	spriteEntity.sprite.setTexture(spriteEntity.texture);
	spriteEntity.sprite.setTextureRect(rectSourceSprite);
	spriteEntity.sprite.setScale(2.0f, 2.0f);
	spriteEntity.sprite.setPosition(xPos, yPos);
	present = 1;
	Plants::typeRepeater = 1;

}
Repeater::~Repeater() {}
void Repeater::display(sf::RenderWindow & Window) {
	cout << "dilo ka shooter hy mera skooter lets go peashooter!!!" << endl;
	Window.draw(spriteEntity.sprite);
}
void Repeater::takeDamage()
{
	cout << " ";
	this->hitPoints--;
}
void Repeater::collisionCheck(Zombie** &zombieEntities, int size, Tile**& grid)
{
	for (int i = 0; i < size; i++)
	{
		if (zombieEntities[i]->position.getX() < position.getX() + 83 && zombieEntities[i]->position.getX() > position.getX() - 83 && zombieEntities[i]->position.getY() == position.getY())
		{
			if (spriteEntity.clockEntity.getElapsedTime().asSeconds() >= 2) {
				cout << "Repeater has collided with zombie" << endl;
				takeDamage();
				spriteEntity.clockEntity.restart();
			}
		}
	}
		for (int i = 0; i < numOfPea; i++) {
			if (peaPtr[i].isPresent == 1)
			peaPtr[i].collisionCheck(zombieEntities, size,peaGenerated);
		}
}
void Repeater::magic(int& coins1)
{
	cout << "Repeater has shot lesgooo" << endl;
	if (peaGenerated == 0) {
		if(peaPtr==nullptr)generatePea();
		else {
			delete[] peaPtr;
			generatePea();
		}
	}
	else {
		peaPtr->movement();
	}
}
void Repeater::generatePea() {
	cout << "Repeater geberating pea" << endl;
	peaPtr = new NormalPea[2];
	for (int i = 0; i < 2; i++) {
		peaPtr[i].setX(this->position.getX());
		peaPtr[i].setY(this->position.getY());
		peaPtr[i].setH(1);
		peaPtr[i].setW(1);
		peaPtr[i].setHit(1);
		peaPtr[i].setSpeed(1);
	}
	peaGenerated = 1;
}
