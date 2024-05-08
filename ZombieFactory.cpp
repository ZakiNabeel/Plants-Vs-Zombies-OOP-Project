#include"ZombieFactory.h"
ZombieFactory::ZombieFactory(int s) :size(s), current(0) {
	zombiePtr = new Zombie*[size];
	addZombies(1200, ((rand() % 5) + 1) * 100,1,1,3,2);
}
ZombieFactory::~ZombieFactory() {
	for (int i = 0; i < size; i++) {
		delete zombiePtr[i];
	}
	delete[] zombiePtr;
}
void ZombieFactory::addZombies(int xPos, int yPos, int h=1, int w=1, int hit=3, int s=1) {
	int check = 0;
	while (current < size) {
		check=rand() % 5;
		cout << check << "-------------------" << check << endl;
		if(check==0)zombiePtr[current] = new SimpleZombies(1200 + 100*(rand()%3), ((rand() % 5)* 100) + 70, h, w, hit, s);
		else if(check ==1)zombiePtr[current] = new FootballZombies(1200 + 100 * (rand() % 3), ((rand() % 5) * 100) + 70, h, w, hit, s);
		else if (check == 2)zombiePtr[current] = new DolphinRiderZombies(1200 + 100 * (rand() % 3), ((rand() % 5) * 100) + 70, h, w, hit, s);
		else if(check ==3)zombiePtr[current] = new FlyingZombies(1200 + 100 * (rand() % 3), ((rand() % 5) * 100) + 70, h, w, hit, s);
		else if(check==4)zombiePtr[current] = new DancingZombies(1200 + 100 * (rand() % 3), ((rand() % 5) * 100) + 70, h, w, hit, s);
		++current;
		cout << "Added " <<current<< endl;
	}
}
void ZombieFactory::display(sf::RenderWindow& Window) {
	for (int i = 0; i < size; i++) {
		if (zombiePtr[i] != nullptr) {
			//cout << "Displayed" << endl;
			(*(zombiePtr[i])).display(Window);
		}
	}
}
void ZombieFactory::updateZombies() {
	for (int i = 0; i < size; i++) {
		if (zombiePtr[i] != nullptr) {
			(*(zombiePtr[i])).movement();
		}
	}
}
void ZombieFactory::chekCollisionRumble(Plants**& plantEntities, int size)
{
	for (int i = 0; i < this->current; i++) {
		if (zombiePtr[i] != nullptr) {
			(*(zombiePtr[i])).collisionCheck(plantEntities,size);
		}
	}
}

int ZombieFactory::getSize() {
	return this->size;
}

Zombie**& ZombieFactory::getZombiePtr() {
	return zombiePtr;
}

