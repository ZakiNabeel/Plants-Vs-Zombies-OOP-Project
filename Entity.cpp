#include"Entity.h"

Entity::Entity(int xPos, int yPos, int h, int w, int hitNum):position(xPos, yPos),size(h,w),hitPoints(hitNum){
	cout << "Entity constructor" << endl;
}
Entity::~Entity(){}
void Entity::display(sf::RenderWindow& Window) {

}
bool Entity::collisionViaZombie(){ return 1; }
bool Entity::collisionCheck() { return 1; }
bool Entity::collisionViaPlant() { return 1; }
bool Entity::collisionViaLawnMover() { return 1; }
bool Entity::collisionViaPea() { return 1; }
void Entity::takeDamage() {
	(this->hitPoints)--;
}
bool collisionViaCherryBomb(){ return 1; }

void Entity::healthCheck() {
if (this->hitPoints == 0) this->~Entity();
}
