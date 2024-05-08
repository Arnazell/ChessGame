#pragma once
#include "Figure.h"

#include <string>

class Pawn : public Figure
{
public:
    // Konstruktor
    Pawn(Team team, int xIND, int yIND, SFML_manager* graphics, Assets* resources);

    // Draw
    void draw();
    sf::Texture loaded;
};