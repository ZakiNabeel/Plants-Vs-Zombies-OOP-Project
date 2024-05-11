#include "Cherrybomb.h"
Cherrybomb::Cherrybomb(int xPos, int yPos, int h, int w, int hp) : NonShooter(xPos, yPos, h, w, hp) {
	cout << "In Cherrybomb constructor" << endl;
	spriteEntity.texture.loadFromFile("cherryBomb.png");
	sf::IntRect rectSourceSprite(0, 0, 35, 30);
	spriteEntity.sprite.setTexture(spriteEntity.texture);
	spriteEntity.sprite.setTextureRect(rectSourceSprite);
	spriteEntity.sprite.setScale(2.0f, 2.0f);
	spriteEntity.sprite.setPosition(xPos, yPos);
	present = 1;
	Plants::typeCherryBomb = 1;
}
Cherrybomb::~Cherrybomb() {}
void Cherrybomb::display(sf::RenderWindow& Window) {
	Window.draw(spriteEntity.sprite);
	//cout << "CherryBomb displayed" << endl;
}
void Cherrybomb::takeDamage()
{
	cout << "     ";
	this->hitPoints -= 1;
}
void Cherrybomb::collisionCheck(Zombie**& zombieEntities, int size, Tile**& grid) {
	for (int i = 0; i < size; i++)
	{
		if (zombieEntities[i]->position.getX() < position.getX() + 83 && zombieEntities[i]->position.getX() > position.getX() - 83 && zombieEntities[i]->position.getY() == position.getY())
		{
			if (spriteEntity.clockEntity.getElapsedTime().asSeconds() >= 2) {
				cout << "Cherrybomb has collided with zombie" << endl;
				takeDamage();
				spriteEntity.clockEntity.restart();
			}
		}
	}
}
void Cherrybomb::magic(int& coins1) {
	cout << "CherryBomb Exploded" << endl;
}