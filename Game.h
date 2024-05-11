#pragma once
#ifndef Game_h
#define Game_h
#include"Level.h"
#include"BeginersGarden.h"
#include <SFML/Graphics.hpp>
#include <ctime>
using namespace std;

class Game {
	int coins;
	Levels* level;
	int levelNumber;
	bool plantClicked;
	sf::RectangleShape grid;
public:
	Game();
	~Game();
	void run();
	int getLevelNumber();
};
#endif // !Game_h