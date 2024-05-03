#pragma once
#ifndef NormalPea_h
#define NormalPea_h
#include"Pea.h"
class NormalPea :public Pea {
public:	
	NormalPea(int xPos, int yPos, int h, int w, int hit, int s);
	~NormalPea();
	void display();
	bool collisionCheck();
	void movement();
};
#endif // !NormalPea_h

