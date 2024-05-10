#include "Assets.h"


Assets::Assets()
{
}

void Assets::init()
{
	textureLoad();
}

void Assets::textureLoad() 
{
	texture_pawn_white.loadFromFile("Res/white-pawn.png");
	texture_pawn_black.loadFromFile("Res/black-pawn.jpg");

	texture_rook_white.loadFromFile("Res/white-rook.png");
	texture_rook_black.loadFromFile("Res/black-rook.png");

	texture_knight_white.loadFromFile("Res/white-knight.png");
	texture_knight_black.loadFromFile("Res/black-knight.png");

	texture_bishop_white.loadFromFile("Res/white-bishop.png");
	texture_bishop_black.loadFromFile("Res/black-bishop.png");

	texture_queen_white.loadFromFile("Res/white-queen.png");
	texture_queen_black.loadFromFile("Res/black-queen.png");

	texture_king_white.loadFromFile("Res/white-king.png");
	texture_king_black.loadFromFile("Res/black-king.png");
}
