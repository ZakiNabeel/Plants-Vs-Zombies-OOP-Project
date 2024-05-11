#pragma once
#ifndef LawnMover_h
#define LawnMover_h
#include<iostream>
#include"Moving.h"
using namespace std;
class LawnMover :public Moving {
public:
	LawnMover(int xPos, int yPos, int h, int w, int hit, int s);
	~LawnMover();
	void movement();
	void display();
	bool collisionCheck();
	//Function Take Damage removed
};
#endif // !LawnMover_h
