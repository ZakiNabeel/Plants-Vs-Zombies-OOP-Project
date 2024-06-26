#include "PlantFactory.h"

PlantFactory::PlantFactory(int n) : size(45), current(0), levelChecker(n) {
	plantPtr = new  Plants * [size];
	sunFlowerSelected = 0;
	peashooterSelected = 0;
	walknutSelected = 0;
	cherrybombSelected = 0;
	repeaterSelected = 0;
	snowPeaSelected = 0;
	grid2 = new Tile * [5];
	for (int i = 0; i < 5; i++) {
		grid2[i] = new Tile[9];
	}
}
PlantFactory::~PlantFactory() {
	for (int i = 0; i < size; i++) {
		delete plantPtr[i];
	}
	delete[] plantPtr;
}
void PlantFactory::addPlant(int xPos, int yPos, int h = 1, int w = 1, int hit = 3) {
	if (xPos >= 250 && xPos <= 800 && yPos >= 70 && yPos <= 570) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 9; j++) {
				if (xPos >= grid2[i][j].getX() && xPos <= grid2[i][j].getX() + grid2[i][j].getWidth() && yPos >= grid2[i][j].getY() && yPos <= grid2[i][j].getY() + grid2[i][j].getHeight() && (!grid2[i][j].getSpace())) {
					grid2[i][j].checkPlant = 1;
					if (walknutSelected) {
						plantPtr[current] = new Walknut(grid2[i][j].getX(), grid2[i][j].getY(), h, w, hit);
						current++;
						walknutSelected = 0;
						cout << "WalkNut Made" << endl;
					}
					else if (peashooterSelected) {
						plantPtr[current] = new Peashooter(grid2[i][j].getX(), grid2[i][j].getY(), h, w, hit);
						current++;
						peashooterSelected = 0;
						cout << "PeaShooter made" << endl;
					}
					else if (sunFlowerSelected) {
						plantPtr[current] = new Sunflower(grid2[i][j].getX(), grid2[i][j].getY(), h, w, hit);
						current++;
						sunFlowerSelected = 0;
						cout << "SunFlower Made" << endl;
					}
					else if (repeaterSelected) {
						plantPtr[current] = new Repeater(grid2[i][j].getX(), grid2[i][j].getY(), h, w, hit);
						current++;
						repeaterSelected = 0;
						cout << "Repeater Made" << endl;
					}
					else if (cherrybombSelected) {
						plantPtr[current] = new Cherrybomb(grid2[i][j].getX(), grid2[i][j].getY(), h, w, hit);
						current++;
						cherrybombSelected = 0;
						cout << "CherryBomb Made" << endl;
					}
					else if (snowPeaSelected) {
						plantPtr[current] = new SnowPea(grid2[i][j].getX(), grid2[i][j].getY(), h, w, hit);
						current++;
						snowPeaSelected = 0;
						cout << "SnowPea Made" << endl;
					}
				}
			}
		}
	}
}
void PlantFactory::display(sf::RenderWindow& Window) {
	for (int i = 0; i < this->current; i++) {
		if (plantPtr[i] != nullptr) {
			(*(plantPtr[i])).display(Window);
		}
	}
}

void PlantFactory::addGrid(Tile**& grid) {
	this->grid2 = grid;
}

void PlantFactory::updatePlant() {
	for (int i = 0; i < this->current; i++) {
		cout << "mAgico before" << endl;
		(*(plantPtr[i])).magic();
		cout << "mAgico after" << endl;
	}
}

void PlantFactory::chekCollisionRumble() {

}