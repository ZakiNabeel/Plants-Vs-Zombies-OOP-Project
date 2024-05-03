#pragma once
#ifndef Game_h
#define Game_h
#include"Level.h"
#include"BeginersGarden.h"
#include <SFML/Graphics.hpp>
#include <ctime>
using namespace std;

class Game {
public:
	Levels* level;
	int levelNumber;
	Game();
	~Game();
	void run();
};
#endif // !Game_h

