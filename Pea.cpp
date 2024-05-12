#include"Pea.h"
Pea::Pea(int xPos, int yPos, int h, int w, int hit, int s = 1) : Moving(xPos, yPos, h, w, hit, 5) {
	this->isPresent = 0;
}
Pea::~Pea(){}
void Pea::display(sf::RenderWindow & Window){
	cout << "abs";
}
void Pea::movement() {
	movementRight();
	cout << "cnuw";
}
void Pea::collisionCheck(Zombie**& zombieEntities, int size, bool &peaGenerated, int& numZom) {
	for (int i = 0; i < size; i++)
	{
		if (position.getX() > 1400) {
			isPresent = 0;
			peaGenerated = 0;
		}
		else if((zombieEntities[i]->position.getX() >= position.getX() && zombieEntities[i]->position.getX() <= position.getX() + 10) && (zombieEntities[i]->position.getY() >= position.getY()-20 && zombieEntities[i]->position.getY() <= position.getY() + 20))
		{
			position.setX(-100);
			position.setY(-100);
			zombieEntities[i]->hitPoints--;
			if (zombieEntities[i]->hitPoints == 0)
			{
				zombieEntities[i]->position.setX(-100);
				zombieEntities[i]->position.setY(-100); 
				--numZom;
			}			
			isPresent = 0;
			peaGenerated = 0;
		}
	}
}
void Pea::takeDamage() {
	cout << "Peacsssssssssssss";
}
void Pea::setX(int x) {
	position.setX(x);
}
void Pea::setY(int y) {
	position.setY(y);
}
void Pea::setH(int h) {
	size.setHeight(h);
}
void Pea::setW(int w) {
	size.setWidth(w);
}
void Pea::setHit(int hit) {
	hitPoints = hit;
}
void Pea::setSpeed(int s) {
	speed = s;
}
