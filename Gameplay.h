#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#pragma once

#include "SFML/Graphics.hpp"
#include "Game.h"

class Gameplay : public GameState
{
public:
    Gameplay();
    ~Gameplay();

    void update(sf::RenderWindow* window);
    void render(sf::RenderWindow* window);


private:
    sf::Event event;
    sf::Clock clock;
    float dt;

};

#endif