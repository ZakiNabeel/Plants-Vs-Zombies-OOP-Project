#pragma once
#ifndef Walknut_H
#define Walknut_H
#include "NonShooter.h"
class Walknut : public NonShooter
{
public:
	Walknut(int xPos, int yPos, int h, int w, int hp);
	~Walknut();
	void display();
	void takeDamage();
	bool collisionCheck();
};
#endif