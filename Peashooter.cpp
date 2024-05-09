#include "Peashooter.h"
#include "SFML/Graphics.hpp"
Peashooter::Peashooter(int xPos, int yPos, int h, int w, int hit) : Shooter(xPos, yPos, h, w, hit) {
	spriteEntity.texture.loadFromFile("peaShooter.png");
	sf::IntRect rectSourceSprite(0, 0, 97, 111);
	spriteEntity.sprite.setTexture(spriteEntity.texture);
	spriteEntity.sprite.setTextureRect(rectSourceSprite);
	spriteEntity.sprite.setScale(0.8f, 0.8f);
	spriteEntity.sprite.setPosition(xPos, yPos);
	cout << "Peashooter Constructor CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC" << endl;
	peaGenerated = 0;
	Shooter::numOfPea = 1;
	present = 1;
	Plants::typePeaShooter = 1;
}
Peashooter::~Peashooter() {}
void Peashooter::takeDamage()
{
	cout << "     ";
	this->hitPoints--;
}
bool Peashooter::isPresent() {
	return this->present;
}


void Peashooter::display(sf::RenderWindow & Window) {
	if(isPresent())
	Window.draw(spriteEntity.sprite);
	cout << "PeaShooter Displayed" << endl;
	for (int i = 0; i < numOfPea; i++) {
		if (peaPtr[i].isPresent == 1)
		peaPtr[i].display(Window);
	}
}
void Peashooter::collisionCheck( Zombie** &zombieEntities, int size, Tile**& grid)
{
	cout << "--------------------COLLISSION FUNCTOPN CALLED-----------------------" << endl;
	for (int i = 0; i < size; i++)
	{
		if ((zombieEntities[i]->position.getX() >= position.getX() && zombieEntities[i]->position.getX() <= position.getX() + 10) && (zombieEntities[i]->position.getY() == position.getY()))
		{
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 9; j++) {
					if (grid[i][j].getX() == position.getX() && grid[i][j].getY() == position.getY()) {
						grid[i][j].checkPlant=0;
					}
				}
			}
			
			position.setX(-100);
			position.setY(-100);
			zombieEntities[i]->movementRight();
			//spriteEntity.clockEntity.restart();
			cout << "--------------------COLLISSION DETECTED-----------------------" << endl;
			if (spriteEntity.clockEntity.getElapsedTime().asSeconds() >= 2) {
				cout << "Peashooter has collided with zombie" << endl;
				plantExists = 0;
				present = 0;	
				position.setX(-100);
				position.setY(-100);
				takeDamage();
				if (healthCheck())
				{
					plantExists = 0;
					present = 0;
				}
				spriteEntity.clockEntity.restart();
			}
		}
	}
	if (peaGenerated == 1) {
		for (int i = 0; i < numOfPea; i++) {
			peaPtr[i].collisionCheck(zombieEntities, size);
		}
	}
}
void Peashooter::magic()
{
	cout << "PeaShooter : " << position.getX() << " " << position.getY() << endl;
	cout << "Peashooter has shot" << endl;
	if(peaGenerated==0)generatePea();
	if (peaGenerated == 1) {
		peaPtr->movement();
	}
}

void Peashooter::generatePea()
{
	cout << "Pea generated Pea Shooter" << endl;
	peaPtr = new NormalPea(position.getX()+83, position.getY(), 1, 1, 0, 3);
	peaGenerated = 1;
	for (int i = 0; i < numOfPea; i++) {
		peaPtr[i].isPresent = 1;
	}
}