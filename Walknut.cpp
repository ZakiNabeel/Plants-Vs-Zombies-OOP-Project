#include "Walknut.h"
Walknut::Walknut(int xPos, int yPos, int h, int w, int hit) : NonShooter(xPos, yPos, h, w, hit) {
	spriteEntity.texture.loadFromFile("WalknuttHighQ.png");
	sf::IntRect rectSourceSprite(0,0,28,31);
	spriteEntity.sprite.setTexture(spriteEntity.texture);
	spriteEntity.sprite.setTextureRect(rectSourceSprite);
	spriteEntity.sprite.setScale(2.0f, 2.0f);
	spriteEntity.sprite.setPosition(xPos, yPos);
	present = 1;
	Plants::typeWalknut = 1;
}
Walknut::~Walknut() {}
void Walknut::takeDamage()
{
	cout << " walk";	
	this->hitPoints--;
}
void Walknut::display(sf::RenderWindow & Window) {
	Window.draw(spriteEntity.sprite);
	cout << "Displayed WalkNutt" << endl;
}
void Walknut::collisionCheck(Zombie**&zombieEntities, int size, Tile**& grid)
{
	for (int i = 0; i < size; i++)
	{
		if (zombieEntities[i]->position.getX() < position.getX() + 83 && zombieEntities[i]->position.getX() > position.getX() - 83 && zombieEntities[i]->position.getY() == position.getY())
		{
			if (spriteEntity.clockEntity.getElapsedTime().asSeconds() >= 2)
			{
				cout<<"Walknut has collided with zombie"<<endl;
				takeDamage();
				spriteEntity.clockEntity.restart();
			}
		}
	}	
	cout << "Walknut Collision Check" << endl;
}
void Walknut::magic(int& coins1) {
	cout << "Walknut Rolled" << endl;
}