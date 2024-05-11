#include"Sun.h"
Sun::Sun(int xPos, int yPos, int h, int w, int hit, int s = 1) : Moving(xPos, yPos, h, w, hit, s) {
	spriteEntity.texture.loadFromFile("Sun.png");
	sf::IntRect rectSourceSprite(0, 0, 500, 500);
	spriteEntity.sprite.setTexture(spriteEntity.texture);
	spriteEntity.sprite.setTextureRect(rectSourceSprite);
	spriteEntity.sprite.setScale(0.1f, 0.1f);
	spriteEntity.sprite.setPosition(xPos, yPos);

}
Sun::~Sun(){}
void Sun::display(sf::RenderWindow & Window){
	cout << "nfuicnweiuwen";
	Window.draw(spriteEntity.sprite);
}

void Sun::movement() {
	if (position.getY() <= 200) movementVertical();
}
bool Sun::collisionCheck() {
	cout << "Sun";
	return 1;
}
void Sun::takeDamage() {
	cout << "Suncacsssssssssssss";
}
sf::Sprite Sun::getSpriteEntity() {
	return spriteEntity.sprite;
}

