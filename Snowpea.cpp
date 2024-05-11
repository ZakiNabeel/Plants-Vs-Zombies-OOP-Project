#include"SnowPea.h"
SnowPea::SnowPea(int xPos, int yPos, int h, int w, int hp):Shooter(xPos,yPos,h,w,hp){
	cout << "SnowPea Constructor" << endl;
	spriteEntity.texture.loadFromFile("SnowPea.png");
	sf::IntRect rectSourceSprite(0, 0, 30, 32);
	spriteEntity.sprite.setTexture(spriteEntity.texture);
	spriteEntity.sprite.setTextureRect(rectSourceSprite);
	spriteEntity.sprite.setScale(2.0f, 2.0f);
	spriteEntity.sprite.setPosition(xPos, yPos);
}
SnowPea::~SnowPea(){}
void SnowPea::display(sf::RenderWindow& Window) {
	Window.draw(spriteEntity.sprite);
}
void SnowPea::takeDamage() {
	cout << "Take Damage SnowPea" << endl;
	
}
bool SnowPea::collisionCheck() {
	cout << "Collision Check Snow Pea" << endl;
	return 1;
}
void SnowPea::generatePea() {
	cout << "Snow Pea generating Pea" << endl;
	peaPtr = new WhitePea(position.getX(), position.getY(), 1, 1, 0, 1);
}
void SnowPea::magic() {
	cout << "Snow Pea Magic" << endl;
}
