#include "Sunflower.h"
Sunflower::Sunflower(int xPos, int yPos, int h, int w, int hit) :NonShooter(xPos, yPos, h, w, hit){
	sunPtr = nullptr;
	spriteEntity.texture.loadFromFile("sunFlower (2).png");
	sf::IntRect rectSourceSprite(341, 117, 113, 117);
	spriteEntity.sprite.setTexture(spriteEntity.texture);
	spriteEntity.sprite.setTextureRect(rectSourceSprite);
	spriteEntity.sprite.setScale(0.7f, 0.7f);
	spriteEntity.sprite.setPosition(xPos, yPos);
	cout << "Sunflower Constructor CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC" << endl;
	sunGenerated = 0;
	present = 1;
	Plants::typeSunFlower = 1;
}
Sunflower::~Sunflower() {
	delete[] sunPtr;
	sunPtr = nullptr;
}
void Sunflower::display(sf::RenderWindow & Window) {
	Window.draw(spriteEntity.sprite);
	//cout << "SunFlower displayed, now get some sunlight" << endl;
	if (sunGenerated == 1 && sunPtr!=nullptr) {
		sunPtr[0].display(Window);
	}
}
void Sunflower::takeDamage()
{
		this->hitPoints--;
}
void Sunflower::collisionCheck(Zombie** &zombieEntities, int size, Tile**& grid, int& numZom)
{
	for (int i = 0; i < size; i++)
	{
		if ((zombieEntities[i]->position.getX() >= position.getX() + 50 && zombieEntities[i]->position.getX() <= position.getX() + 80) && (zombieEntities[i]->position.getY() >= position.getY() - 20) && (zombieEntities[i]->position.getY() <= position.getY() + 20)) {
			if (spriteEntity.clockEntity.getElapsedTime().asSeconds() >= 2)
			{
			//cout << "Sunflower has collided with zombie" << endl;
			takeDamage();
			spriteEntity.clockEntity.restart();
			}
		}
	}
}
void Sunflower::generateSun(int& coins1)
{
	coins1 += 100;
	sunPtr = new Sun(position.getX()+83, position.getY(), 1, 1, 0,1);
	sunGenerated = 1;
	spriteEntity.clockEntity.restart();
}

void Sunflower::magic(int& coins1) {
	if (sunGenerated == 0 && spriteEntity.clockEntity.getElapsedTime().asSeconds() > 10) {
		generateSun(coins1);
		spriteEntity.clockEntity.restart();
	}
	else {
		if (spriteEntity.clockEntity.getElapsedTime().asSeconds() < 2 && sunGenerated == 1)
			sunPtr->movement();
		else if (spriteEntity.clockEntity.getElapsedTime().asSeconds() > 5 && sunGenerated == 1) { // 5 seconds as an example
			delete sunPtr;
			sunPtr = nullptr;
			sunGenerated = 0;
			spriteEntity.clockEntity.restart();
		}
	}
}
