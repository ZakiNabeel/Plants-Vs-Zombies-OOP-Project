#pragma once
#ifndef Cherrybomb_H
#define Cherrybomb_H
#include "NonShooter.h"
class Cherrybomb : public NonShooter
{
public:
	Cherrybomb(int xPos, int yPos, int h, int w, int hp);
	~Cherrybomb();
	void movement();
	void display();
	void takeDamage();
	bool collisionCheck();
};
#endif