#include"ZombieFactory.h"
ZombieFactory::ZombieFactory(int s) :size(s), current(0) {
	zombiePtr = new Zombie*[size];
	addZombies(1200, ((rand() % 5) + 1) * 100,1,1,3,5);
}
ZombieFactory::~ZombieFactory() {
	for (int i = 0; i < size; i++) {
		delete zombiePtr[i];
	}
	delete[] zombiePtr;
}
void ZombieFactory::addZombies(int xPos, int yPos, int h=1, int w=1, int hit=3, int s=10) {
	//int check = 0;
	//while (current < size) {
	//	//check=rand() % 5;
	//	/*if(check==0)*/zombiePtr[current] = new SimpleZombies(1200, ((rand() % 5)+1)*, h, w, hit, s);
	//	//else if(check==1)zombiePtr[current] = new FootballZombies(1200, ((rand() % 5) + 1) * 100, h, w,hit, s);
	//	//else if (check == 2)zombiePtr[current] = new DolphinRiderZombies(1200, 300, h, w,hit, s);
	//	//else if(check==3)zombiePtr[current] = new FlyingZombies(1200, ((rand() % 5) + 1) * 100, h, w,hit, s);
	//	//else if(check==4)zombiePtr[current] = new DancingZombies(1200, ((rand() % 5) + 1) * 100, h, w,hit, s);
	//	++current;
	//	cout << "Added " <<current<< endl;
	//}
	zombiePtr[0] = new SimpleZombies(1200, 80, h, w, hit, s);
	zombiePtr[1] = new SimpleZombies(1200, 180, h, w, hit, s);
	zombiePtr[2] = new SimpleZombies(1200, 280, h, w, hit, s);
	zombiePtr[3] = new SimpleZombies(1200, 380, h, w, hit, s);
	zombiePtr[4] = new SimpleZombies(1200, 480, h, w, hit, s);

}
void ZombieFactory::display(sf::RenderWindow& Window) {
	for (int i = 0; i < size; i++) {
		if (zombiePtr[i] != nullptr) {
			cout << "Displayed" << endl;
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
