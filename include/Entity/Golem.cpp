#include "Golem.h"

Golem::Golem(Game* g)
{
    sprite = new DynamicSprite(g->p->s_golem,1800,65,64,64,12);
    health = 100;
    armour = 99;
    power = 20;
    character = 1;
}

Golem::~Golem()
{

}