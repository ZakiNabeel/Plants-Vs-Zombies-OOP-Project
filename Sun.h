#pragma once
#ifndef Sun_h
#define Sun_h
#include"Moving.h"
class Sun:public Moving{
public:
	Sun(int xPos, int yPos, int h, int w, int hit, int s);
	~Sun();
	void movement();
	void display();
};
#endif // !Sun_h

