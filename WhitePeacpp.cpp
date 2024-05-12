#include"WhitePea.h"
WhitePea::WhitePea(int xPos, int yPos, int h, int w, int hit, int s = 1) : Pea(xPos, yPos, h, w, hit, s) {
	spriteEntity.texture.loadFromFile("WhitePea.png");
	sf::IntRect rectSourceSprite(0, 0, 135, 135);
	spriteEntity.sprite.setTexture(spriteEntity.texture);
	spriteEntity.sprite.setTextureRect(rectSourceSprite);
	spriteEntity.sprite.setScale(0.9f, 0.9f);
	spriteEntity.sprite.setPosition(xPos, yPos);
}
WhitePea::~WhitePea(){

}
void WhitePea::display(sf::RenderWindow& Window){
	cout << "eieuif";
	Window.draw(spriteEntity.sprite);
}
void WhitePea::movement() {
	movementRight();
	cout << "WhitePea";
}
void WhitePea::collisionCheck(Zombie ** & zombieEntities, int size, bool& peaGenerated, int& numZom) {
	Pea::collisionCheck(zombieEntities, size, peaGenerated,numZom);
}
void WhitePea::takeDamage() {
	cout << "WhitePeacsssssssssssss";
}
sf::Sprite WhitePea::getSpriteEntity() {
	return spriteEntity.sprite;
}