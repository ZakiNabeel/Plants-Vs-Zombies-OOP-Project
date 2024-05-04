#pragma once
#ifndef Shooter_H
#define Shooter_H
#include "Plants.h"
#include "Pea.h"
class Shooter : public Plants
{
	Pea* peaPtr;
public:
	virtual void shoot() = 0;
	Shooter(int xPos, int yPos, int h, int w, int hp);
	~Shooter();
	Pea& getPea() const;
	void display();
	void takeDamage();
	bool collisionCheck();
};
#endif