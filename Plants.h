#pragma once
#ifndef Plants_H
#define Plants_H
#include "Entity.h"
#include <SFML/Graphics.hpp>
class Plants : public Entity
{
public:
	Plants(int xPos, int yPos, int h, int w, int);
	~Plants();
	virtual bool collisionCheck() = 0;
};
#endif