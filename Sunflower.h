#pragma once
#ifndef Sunflower_H
#define Sunflower_H
#include "Sun.h"
#include "NonShooter.h"
class Sunflower : NonShooter
{
	Sun* sunPtr;
public:
	Sunflower(int xPos, int yPos, int h, int w, int hit);
	~Sunflower();
	void display();
	void takeDamage();
	bool collisionCheck();
};
#endif