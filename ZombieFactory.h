#pragma once
#ifndef ZombieFactory_h
#define ZombieFactory_h
#include"Entity.h"
#include"Zombie.h"
#include"Plants.h"
#include"SimpleZombies.h"
#include"FootballZombies.h"
#include"DolphinRiderZombies.h"
#include"FlyingZombies.h"
#include"DancingZombies.h"
#include<cstdlib>
#include<ctime>
class ZombieFactory {
	int size;
	int current;
	Zombie** zombiePtr;
public:
	ZombieFactory(int);
	~ZombieFactory();                                              
	void addZombies(int, int, int, int, int, int);
	void display(sf::RenderWindow &Window);
	void updateZombies();
	void chekCollisionRumble(Plants ** &, int);
	int getSize();
	Zombie**& getZombiePtr();
};
#endif // !ZombieFactory_h

