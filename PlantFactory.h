#pragma once
#ifndef PLANT_FACTORY_H
#define PLANT_FACTORY_H

#include <SFML/Graphics.hpp>
#include "Plants.h"
#include "Shooter.h"
#include "NonShooter.h"

class PlantFactory {
public:
    static Plants* createPlant(const std::string& type, sf::Vector2f pos);
};

#endif // PLANT_FACTORY_H
