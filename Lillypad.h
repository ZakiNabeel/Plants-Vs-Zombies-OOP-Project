#pragma once
#ifndef Lillypad_H
#define Lillypad_H
#include "Entity.h"
class Lillypad : Entity
{
public:
	Lillypad(int xPos, int yPos, int h, int w, int hp);
	~Lillypad();
	void display();
	bool collisionCheck();
};
#endif