#include "Walknut.h"
Walknut::Walknut(int xPos, int yPos, int h, int w, int hit) : NonShooter(xPos, yPos, h, w, hit) {
	spriteEntity.texture.loadFromFile("WalknuttHighQ.png");
	sf::IntRect rectSourceSprite(0,0,28,31);
	spriteEntity.sprite.setTexture(spriteEntity.texture);
	spriteEntity.sprite.setTextureRect(rectSourceSprite);
	spriteEntity.sprite.setScale(2.0f, 2.0f);
	spriteEntity.sprite.setPosition(xPos, yPos);
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
bool Walknut::collisionCheck()
{
	cout << "walknut";
	return 1;
}
void Walknut::magic() {
	cout << "Walknut Rolled" << endl;
}