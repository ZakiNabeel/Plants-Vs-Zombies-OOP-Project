#include"SimpleZombies.h"
SimpleZombies::SimpleZombies(int xPos, int yPos, int h, int w, int hit, int s) : Zombie(xPos, yPos, h, w, hit, s) {
	spriteEntity.texture.loadFromFile("SimpleZombie.png");
	spriteEntity.sprite.setTexture(spriteEntity.texture);
	rectSourceSprite.left = 0;
	rectSourceSprite.top = 0;
	rectSourceSprite.width = 200;
	rectSourceSprite.height = 135;
	spriteEntity.sprite.setTextureRect(rectSourceSprite);
	spriteEntity.sprite.setPosition(xPos, yPos);
	spriteEntity.sprite.setScale(0.65f, 0.70f);
	spriteEntity.clockEntity.restart();
}
SimpleZombies::~SimpleZombies(){}
void SimpleZombies::display(sf::RenderWindow & Window) {		
	if (spriteEntity.clockEntity.getElapsedTime().asMicroseconds()> 0.1) {
		if (rectSourceSprite.left == 9000 && spriteEntity.coordinateRightTouch == false) {
			spriteEntity.coordinateRightTouch = true;
			spriteEntity.coordinateLeftTouch = false;
			rectSourceSprite.left -=200;
			spriteEntity.sprite.setTextureRect(rectSourceSprite);
		}
		else if (rectSourceSprite.left == 0 && spriteEntity.coordinateRightTouch == true) {
			spriteEntity.coordinateRightTouch = false;
			spriteEntity.coordinateLeftTouch = true;
			rectSourceSprite.left += 200;
			spriteEntity.sprite.setTextureRect(rectSourceSprite);
		}
		else if (spriteEntity.coordinateRightTouch == true && spriteEntity.coordinateLeftTouch == false) {
			rectSourceSprite.left -= 200;
			spriteEntity.sprite.setTextureRect(rectSourceSprite);
		}
		else {
			rectSourceSprite.left += 200;
			spriteEntity.sprite.setTextureRect(rectSourceSprite);
		}
	}
	Window.draw(spriteEntity.sprite);
//	cout << "SimpleZombies Displayed" << endl;
}
void SimpleZombies::movement() {
	movementLeft();
	spriteEntity.sprite.setPosition(position.getX(), position.getY());
//	cout << "SimpleZombies Moved" << endl;
}
void  SimpleZombies::takeDamage() {
	hitPoints -= 1;
}
bool  SimpleZombies::collisionCheck(){ return 1; }