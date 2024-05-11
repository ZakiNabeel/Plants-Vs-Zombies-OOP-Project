#pragma once
#ifndef DolphinRiderZombies_h
#define DolphinRiderZombies_h
#include "Zombie.h"

class DolphinRiderZombies : public Zombie {
public:
    DolphinRiderZombies(int xPos, int yPos, int h, int w, int hit, int s);
    ~DolphinRiderZombies();
    void movement();
    void takeDamage();
    void display(sf::RenderWindow& Window);
    bool collisionCheck();
};

#endif // !DolphinRiderZombies_h

