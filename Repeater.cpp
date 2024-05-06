#include "Repeater.h"
Repeater::Repeater(int xPos, int yPos, int h, int w, int hit) : Shooter(xPos, yPos, h, w, hit) {
	spriteEntity.texture.loadFromFile("Repeater.png");
	sf::IntRect rectSourceSprite(0, 0, 35, 35);
	spriteEntity.sprite.setTexture(spriteEntity.texture);
	spriteEntity.sprite.setTextureRect(rectSourceSprite);
	spriteEntity.sprite.setScale(2.0f, 2.0f);
	spriteEntity.sprite.setPosition(xPos, yPos);

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
bool Repeater::collisionCheck()
{
	cout << "Peashooter collided";
	return 1;
}
void Repeater::magic()
{
	cout << "Repeater has shot lesgooo" << endl;
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
}
