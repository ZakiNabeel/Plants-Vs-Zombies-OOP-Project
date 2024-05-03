#pragma once
#ifndef Pea_h
#define Pea_h
#include<iostream>
using namespace std;
#include"Moving.h"
class Pea :public Moving {
public:	
	Pea(int xPos, int yPos, int h, int w, int hit, int s);
	~Pea();
	void display();
	void movement();
	bool collisionCheck();
	//Take Damage is removed
};
#endif // !Pea_h

