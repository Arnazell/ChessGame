#pragma once
#include "Figure.h"
#include "Board.h"

#include <string>

class Bishop : public Figure
{
public:
    // Konstruktor
    Bishop(Team team, int xIND, int yIND, SFML_manager* graphics, Assets* resources, Board* board);

    // Generowanie przestrzeni ruchow
    void generate_move_space() override;

    // Generowanie przestrzeni atakow: ciezka sprawa tylko w przypadku pionka
    void ganerate_attack_space();


    sf::Texture loaded;
};