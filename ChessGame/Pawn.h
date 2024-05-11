#pragma once
#include "Figure.h"
#include "Board.h"

#include <string>

class Pawn : public Figure
{
public:
    // Konstruktor
    Pawn(Team team, int xIND, int yIND, SFML_manager* graphics, Assets* resources, Board* board);

    // Generowanie przestrzeni ruchow
    void generate_move_space() override;


    sf::Texture loaded;
};