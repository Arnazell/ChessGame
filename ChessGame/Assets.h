#pragma once
#include <SFML/Graphics.hpp>

// -------------------------------------------------------------------------------------------------------
// klasa przechowuj¹ca dane  - glownie tekstury
// -------------------------------------------------------------------------------------------------------


class Assets
{
public:

	// konstruktor
	Assets();

	// inicjacja
	void init();

	// ladowanie tekstur
	void textureLoad();

	// tekstury
	sf::Texture texture_pawn_white;
	sf::Texture texture_pawn_black;

	sf::Texture texture_rook_white;
	sf::Texture texture_rook_black;

	sf::Texture texture_knight_white;
	sf::Texture texture_knight_black;

	sf::Texture texture_bishop_white;
	sf::Texture texture_bishop_black;

	sf::Texture texture_queen_white;
	sf::Texture texture_queen_black;

	sf::Texture texture_king_white;
	sf::Texture texture_king_black;
};