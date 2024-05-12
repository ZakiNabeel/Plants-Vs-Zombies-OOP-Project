#include "Walknut.h"
Walknut::Walknut(int xPos, int yPos, int h, int w, int hit) : NonShooter(xPos, yPos, h, w, hit) {
	spriteEntity.texture.loadFromFile("WalknuttHighQ.png");
	sf::IntRect rectSourceSprite(0,0,15,105);
	spriteEntity.sprite.setTexture(spriteEntity.texture);
	spriteEntity.sprite.setTextureRect(rectSourceSprite);
	spriteEntity.sprite.setScale(6.0f, 1.0f);
	spriteEntity.sprite.setPosition(xPos, yPos);
	present = 1;
	Plants::typeWalknut = 1;
	coordinateRightTouch = 1;
	coordinateLeftTouch = 0;
}
Walknut::~Walknut() {}
void Walknut::takeDamage()
{
	cout << " walk";	
	this->hitPoints--;
}
void Walknut::display(sf::RenderWindow & Window) {
		if (spriteEntity.clockEntity.getElapsedTime().asSeconds()> 0.1) {
		if (rectSourceSprite.left == 735 && spriteEntity.coordinateRightTouch == true) {
			spriteEntity.coordinateRightTouch = false;
			spriteEntity.coordinateLeftTouch = true;
			rectSourceSprite.left =0;
			spriteEntity.sprite.setTextureRect(rectSourceSprite);
		}
		else if (rectSourceSprite.left == 0) {
			rectSourceSprite.left += 105;
			spriteEntity.sprite.setTextureRect(rectSourceSprite);
		}
		else if (spriteEntity.coordinateRightTouch == true && spriteEntity.coordinateLeftTouch == false) {
			rectSourceSprite.left += 105;
			spriteEntity.sprite.setTextureRect(rectSourceSprite);
		}
		else {
			rectSourceSprite.left += 105;
			spriteEntity.sprite.setTextureRect(rectSourceSprite);
		}
	}		
	Window.draw(spriteEntity.sprite);
}
void Walknut::collisionCheck(Zombie**&zombieEntities, int size, Tile**& grid, int& numZom)
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