#pragma once
#include "Figure.h"

#include <string>

class Bishop : public Figure
{
public:
    // Konstruktor
    Bishop(Team team, int xpos, int ypos, SFML_manager* graphics);

    // Draw
    void draw();
};