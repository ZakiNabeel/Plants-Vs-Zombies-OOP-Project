#include "Sunflower.h"
Sunflower::Sunflower(int xPos, int yPos, int h, int w, int hit) : NonShooter(xPos, yPos, h, w, hit){
	sunPtr = nullptr;
	spriteEntity.texture.loadFromFile("sunFlower (2).png");
	sf::IntRect rectSourceSprite(341, 117, 113, 117);
	spriteEntity.sprite.setTexture(spriteEntity.texture);
	spriteEntity.sprite.setTextureRect(rectSourceSprite);
	spriteEntity.sprite.setScale(0.7f, 0.7f);
	spriteEntity.sprite.setPosition(xPos, yPos);
	cout << "Sunflower Constructor CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC" << endl;
	sunGenerated = 0;
}
Sunflower::~Sunflower() {
	delete[] sunPtr;
}
void Sunflower::display(sf::RenderWindow & Window) {
	Window.draw(spriteEntity.sprite);
	cout << "SunFlower displayed, now get some sunlight" << endl;
	if (sunGenerated == 1) {
		sunPtr[0].display(Window);
		cout << "SUN SUN SUN SUN SUN SUN SUN SUN SUN SUN SUN SUN SUN SUN SUN SUN" << endl;
	}
}
void Sunflower::takeDamage()
{
	if (collisionCheck())
		this->hitPoints--;
}
bool Sunflower::collisionCheck()
{
	return collisionViaZombie();
}
void Sunflower::generateSun()
{
	sunPtr = new Sun(position.getX()+83, position.getY(), 1, 1, 0,1);
	sunGenerated = 1;
}

void Sunflower::magic() {
	if (sunGenerated == 0) {
		generateSun();
		cout << "Sunflower (Post Malone) ny bacha dy dia---------------------------------------------------------" << endl;
	}
	else {
		sunPtr->movement();
	}
}