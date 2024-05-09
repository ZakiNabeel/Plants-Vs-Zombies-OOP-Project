#include"Level.h"
Levels::Levels(int n):numZombies(n*5), zombieFactory(numZombies), plantFactory(n), levelNumber(n){
	if (levelNumber <= 3) {
		grid = new Tile * [5];
		for (int i = 0; i < 5; i++) {
			grid[i] = new Tile[9];
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 9; j++) {
				grid[i][j].setX(250 + j * 83);
				grid[i][j].setY(70 + i * 100);
				grid[i][j].setGridPosition(grid[i][j].getX(), grid[i][j].getY());
			}
		}
	}
	plantFactory.addGrid(grid);
	if(n==1)availablePlants(n);
	peaPtr = nullptr;
	sizePea = 0;
}
void Levels::setNumZombies(int n) {
	this->numZombies = n * 5;
}
Levels::~Levels() {
	for (int i = 0; i < 5; i++) {
		delete[] grid[i];
	}
	delete[] grid;
}


void Levels::display(sf::RenderWindow &Window) {
	//for (int i = 0; i < 5; i++) {
	//	for (int j = 0; j < 9; j++) {
	//		grid[i][j].display(Window);
	//	}
	//}
	zombieFactory.display(Window);
	drawAvailablePlants(levelNumber,Window);
	plantFactory.display(Window);
}

void Levels::update() {
	zombieFactory.updateZombies();
	plantFactory.updatePlant();
	collisionRumble(grid);
	plantFactory.checkExistingPlants();
}
void Levels::availablePlants(int level) {
	if (levelNumber == 1) {
		textureAvailablePlants.loadFromFile("MENU.png");
		sf::IntRect rectSourceSprite(0, 200, 327, 609);
		rectSourceSprite.left = 0;
		rectSourceSprite.top = 0;
		rectSourceSprite.width = 327;
		rectSourceSprite.height = 390;
		spriteAvailablePlants.setTexture(textureAvailablePlants);
		spriteAvailablePlants.setTextureRect(rectSourceSprite);
		spriteAvailablePlants.setScale(0.5f, 0.5f);
		spriteAvailablePlants.setPosition(0,0);
		cout << "Sprite initialized" << endl;
	}
}
void Levels::drawAvailablePlants(int level, sf::RenderWindow & Window) {
	if (level == 1) {
		Window.draw(spriteAvailablePlants);
	}
}

bool Levels::checkMouseClick(sf::RenderWindow& Window, int x, int y) {
	cout << x << endl;
	cout << y << endl;
	if (levelNumber == 1) {
		if (x >= 0 && x <= 327 && y >= 0 && y <= 100 ) {
			cout << "PeaShooter---------------------------------------- " << endl;
			plantFactory.peashooterSelected = 1;
			return 1;
		}
		else if (x >= 0 && x <= 327 && y > 100 && y <= 200) {
			cout << "Sunflower selected--------------------------------" << endl;
			plantFactory.sunFlowerSelected = 1;
			return 1;
		}
		return 0;
	}

}
PlantFactory& Levels::getPlantFactory() {
	return plantFactory;
}

void Levels::collisionRumble(Tile ** & grid) {
	plantFactory.chekCollisionRumble(zombieFactory.getZombiePtr(), zombieFactory.getSize(), grid);
	zombieFactory.chekCollisionRumble(plantFactory.getPlantPtr(),plantFactory.getSize());
}


void Levels::updatePlantFactory(int xPos, int yPos, int h, int w, int hit) {
	plantFactory.addPlant(xPos,yPos,h,w,hit);
}
