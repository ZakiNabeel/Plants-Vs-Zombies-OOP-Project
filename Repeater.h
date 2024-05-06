#pragma once
#ifndef Repeater_H
#define Repeater_H
#include "Shooter.h"
#include "NormalPea.h"
class Repeater : public Shooter
{
public:	
	Repeater(int xPos, int yPos, int h, int w, int hit);
	~Repeater();
	void takeDamage();
	void display(sf::RenderWindow & Window);
	bool collisionCheck();
	void magic();
	void generatePea();
};
#endif