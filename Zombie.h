#pragma once
#ifndef Zombie_h
#define Zombies_h
#include"iostream"
#include"Moving.h"
using namespace std;
class Zombie :public Moving {
public:
	Zombie(int xPos, int yPos, int h, int w, int hit, int s);
	~Zombie();
	void movement();
	void takeDamage() = 0;
	void display(sf::RenderWindow& Window);
	bool collisionCheck() = 0;
};
#endif // !Zombie_h

