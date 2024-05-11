#include"SnowPea.h"
SnowPea::SnowPea(int xPos, int yPos, int h, int w, int hp):Shooter(xPos,yPos,h,w,hp){
	cout << "SnowPea Constructor" << endl;
	spriteEntity.texture.loadFromFile("SnowPea.png");
	sf::IntRect rectSourceSprite(0, 0, 30, 32);
	spriteEntity.sprite.setTexture(spriteEntity.texture);
	spriteEntity.sprite.setTextureRect(rectSourceSprite);
	spriteEntity.sprite.setScale(2.0f, 2.0f);
	spriteEntity.sprite.setPosition(xPos, yPos);
	present = 1;
	Plants::typeSnowPea = 1;
}
SnowPea::~SnowPea(){}
void SnowPea::display(sf::RenderWindow& Window) {
	Window.draw(spriteEntity.sprite);
}
void SnowPea::takeDamage() {
	cout << "Take Damage SnowPea" << endl;
	
}
void SnowPea::collisionCheck(Zombie** &zombieEntities, int size, Tile**& grid, int& numZom) {
	cout << "SnowPea Collision Check" << endl;
	for (int i = 0; i < size; i++) {
		if (zombieEntities[i]->position.getX() < position.getX() + 83 && zombieEntities[i]->position.getX() > position.getX() - 83 && zombieEntities[i]->position.getY() == position.getY())
		{
			if (spriteEntity.clockEntity.getElapsedTime().asSeconds() >= 2) {
				cout << "SnowPea has collided with zombie" << endl;
				takeDamage();
				spriteEntity.clockEntity.restart();
			}
		}
	}
	for (int i = 0; i < numOfPea; i++) {
		if(peaPtr[i].isPresent==1)
		peaPtr[i].collisionCheck(zombieEntities, size,peaGenerated,numZom);
	}
}
void SnowPea::magic(int& coins1) {
	cout << "Snow Pea Magic" << endl;
	cout << "Peashooter has shot" << endl;
	if (peaGenerated == 0)generatePea();
	if (peaGenerated == 1) {
		peaPtr->movement();
	}
}

void SnowPea::generatePea() {
	cout << "Snow Pea generating Pea" << endl;
	if (peaGenerated == 0) {
		peaPtr = new WhitePea(position.getX(), position.getY(), 1, 1, 0, 1);
		peaGenerated = 1;
	}

}
