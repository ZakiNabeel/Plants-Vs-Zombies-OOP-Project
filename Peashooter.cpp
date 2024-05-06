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
}
Peashooter::~Peashooter() {}
void Peashooter::takeDamage()
{
	cout << "     ";
	this->hitPoints--;
}
void Peashooter::display(sf::RenderWindow & Window) {
	Window.draw(spriteEntity.sprite);
	cout << "PeaShooter Displayed" << endl;
	if(peaGenerated==1) peaPtr[0].display(Window);

}
bool Peashooter::collisionCheck()
{
	cout << " inuinduinquifnqeuifnqeuif";
	return 1;
}
void Peashooter::magic()
{
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
}