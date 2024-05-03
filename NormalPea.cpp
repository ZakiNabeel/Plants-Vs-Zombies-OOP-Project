#include"NormalPea.h"
NormalPea::NormalPea(int xPos, int yPos, int h, int w, int hit, int s = 1) : Pea(xPos, yPos, h, w, hit, s) {}
NormalPea::~NormalPea(){}
void NormalPea::display(){}
bool NormalPea::collisionCheck(){
	collisionViaZombie();
	return 1;
}
void NormalPea::movement() {
	movementRight();
}