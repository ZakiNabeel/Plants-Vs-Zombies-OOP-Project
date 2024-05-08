#pragma once
#ifndef LawnMover_h
#define LawnMover_h
#include<iostream>
#include"Moving.h"
#include"Zombie.h"
using namespace std;
class LawnMover :public Moving {
public:
	bool isPresent;
	LawnMover(int xPos, int yPos, int h, int w, int hit, int s);
	~LawnMover();
	void movement();
	void display();
	void collisionCheck(Zombie**& zombieEntities, int);
	//Function Take Damage removed
};
#endif // !LawnMover_h
