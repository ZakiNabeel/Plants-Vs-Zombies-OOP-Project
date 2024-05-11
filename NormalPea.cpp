#include"NormalPea.h"
NormalPea::NormalPea(int xPos=0, int yPos=0, int h=0, int w=0, int hit=0, int s = 0) : Pea(xPos, yPos, h, w, hit, s) {
	spriteEntity.texture.loadFromFile("Pea.png");
	sf::IntRect rectSourceSprite(0, 0, 135, 135);
	spriteEntity.sprite.setTexture(spriteEntity.texture);
	spriteEntity.sprite.setTextureRect(rectSourceSprite);
	spriteEntity.sprite.setScale(0.3f, 0.3f);
	spriteEntity.sprite.setPosition(xPos+83, yPos);
}
NormalPea::~NormalPea(){}
void NormalPea::display(sf::RenderWindow & Window){
	Window.draw(spriteEntity.sprite);
}
void NormalPea::collisionCheck(Zombie ** & zombieEntities, int size, bool &peaGenerated, int& numZom){
	Pea::collisionCheck(zombieEntities, size, peaGenerated,numZom);
}
void NormalPea::movement() {
	movementRight();
}
void NormalPea::takeDamage() {
}
NormalPea::NormalPea() : Pea(0,0,0,0,0,0){
}
sf::Sprite NormalPea::getSpriteEntity() {
	return spriteEntity.sprite;
}

