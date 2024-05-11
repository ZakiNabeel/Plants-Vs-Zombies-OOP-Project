#pragma once
#ifndef Game_h
#define Game_h
#include"Level.h"
#include "Screen.h"
#include"BeginersGarden.h"
#include "MenuScreen.h"
#include "InstructionScreen.h"
#include <SFML/Graphics.hpp>
#include <ctime>
using namespace std;

class Game {
	Levels* level;
	MenuScreen menuScreen;
	InstructionScreen instructionScreen;
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