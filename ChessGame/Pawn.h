#pragma once
#include "Figure.h"

class Pawn : public Figure
{
public:
    // Konstruktor
    Pawn(Team team, unsigned int xpos, unsigned int ypos);
};