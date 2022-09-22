#ifndef PLAYBUTTON_H
#define PLAYBUTTON_H

#pragma once

#include "Button.h"
#include <string>

class PlayButton : public Button
{
public:
    PlayButton(int s, sf::Color c, std::string string, int x, int y);
    ~PlayButton();

    void update(sf::RenderWindow* window, Game* game);
private:

};

#endif