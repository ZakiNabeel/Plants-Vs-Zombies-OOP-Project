#pragma once
#ifndef Repeater_H
#define Repeater_H
#include "Shooter.h"
class Repeater : public Shooter
{
public:
    void shoot() override {
        // Implement repeated shooting logic here
    }	Repeater(int xPos, int yPos, int h, int w, int hit);
	~Repeater();
	void takeDamage();
	void display();
	bool collisionCheck();
};
#endif