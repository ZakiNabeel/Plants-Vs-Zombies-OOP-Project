#include "Cherrybomb.h"
Cherrybomb::Cherrybomb(int xPos, int yPos, int h, int w, int hp) : NonShooter(xPos, yPos, h, w, hp) {
	cout << "In Cherrybomb constructor" << endl;
	spriteEntity.texture.loadFromFile("cherryBomb.png");
	sf::IntRect rectSourceSprite(0, 0, 35, 30);
	spriteEntity.sprite.setTexture(spriteEntity.texture);
	spriteEntity.sprite.setTextureRect(rectSourceSprite);
	spriteEntity.sprite.setScale(2.0f, 2.0f);
	spriteEntity.sprite.setPosition(xPos, yPos);
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
bool Cherrybomb::collisionCheck()
{
	//cout << "nvuiqefuifuiwe";
	return 1;
}
void Cherrybomb::magic() {
	cout << "CherryBomb Exploded" << endl;

}