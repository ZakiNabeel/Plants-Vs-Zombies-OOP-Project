#pragma once
#ifndef WhitePea_h
#define NormalPea_h
#include"Pea.h"
class WhitePea :public Pea {
public:
	WhitePea(int xPos, int yPos, int h, int w, int hit, int s);
	~WhitePea();
	void display();
	bool collisionCheck();
	void movement();
};
#endif // !WhitePea_h

