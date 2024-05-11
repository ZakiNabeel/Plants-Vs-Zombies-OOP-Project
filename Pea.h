#pragma once
#ifndef Pea_h
#define Pea_h
#include<iostream>
using namespace std;
#include"Moving.h"
class Pea : public Moving {
public:	
	Pea(int xPos, int yPos, int h, int w, int hit, int s);
	~Pea();
	void display(sf::RenderWindow& Window);
	void movement();
	bool collisionCheck();
	void takeDamage();
	void setX(int);
	void setY(int);
	void setH(int);
	void setW(int);
	void setHit(int);
	void setSpeed(int);
	virtual sf::Sprite getSpriteEntity() = 0;

	//Take Damage is removed
};
#endif // !Pea_h

