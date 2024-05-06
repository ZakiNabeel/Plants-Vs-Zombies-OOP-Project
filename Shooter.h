#pragma once
#ifndef Shooter_H
#define Shooter_H
#include "Plants.h"
#include "WhitePea.h"
#include"NormalPea.h"
class Shooter : public Plants
{
protected:	
	Pea* peaPtr;
	int numOfPea;
public:
	//virtual void shoot() = 0;
	Shooter(int xPos, int yPos, int h, int w, int hp);
	~Shooter();
	//Pea& getPea() const;
	void display(sf::RenderWindow& Window);
	void takeDamage();
	bool collisionCheck();
	virtual void generatePea() = 0;
	virtual void magic() override;
	void setNumOfPea(int);
	int getNumOfPea();
	Pea* getPeaPtr();
};
#endif