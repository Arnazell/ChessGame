#include "Game.h"

Game::Game(SFML_manager* graphics)
	:graphics(graphics),
	p1(Pawn(Figure::BLACK, 0, 1, graphics)),
	p2(Pawn(Figure::BLACK, 1, 1, graphics)),
	p3(Pawn(Figure::BLACK, 2, 1, graphics)),
	p4(Pawn(Figure::BLACK, 3, 1, graphics)),
	p5(Pawn(Figure::BLACK, 4, 1, graphics)),
	p6(Pawn(Figure::BLACK, 5, 1, graphics)),
	p7(Pawn(Figure::BLACK, 6, 1, graphics)),
	p8(Pawn(Figure::BLACK, 7, 1, graphics)),

	P1(Pawn(Figure::WHITE, 0, 6, graphics)),
	P2(Pawn(Figure::WHITE, 1, 6, graphics)),
	P3(Pawn(Figure::WHITE, 2, 6, graphics)),
	P4(Pawn(Figure::WHITE, 3, 6, graphics)),
	P5(Pawn(Figure::WHITE, 4, 6, graphics)),
	P6(Pawn(Figure::WHITE, 5, 6, graphics)),
	P7(Pawn(Figure::WHITE, 6, 6, graphics)),
	P8(Pawn(Figure::WHITE, 7, 6, graphics)),


	b1(Bishop(Figure::BLACK, 0, 0, graphics)),
	b2(Bishop(Figure::WHITE, 2, 0, graphics))
{
	pieces.push_back(&p1);
	pieces.push_back(&p2);
	pieces.push_back(&p3);
	pieces.push_back(&p4);
	pieces.push_back(&p5);
	pieces.push_back(&p6);
	pieces.push_back(&p7);

	pieces.push_back(&P1);
	pieces.push_back(&P2);
	pieces.push_back(&P3);
	pieces.push_back(&P4);
	pieces.push_back(&P5);
	pieces.push_back(&P6);
	pieces.push_back(&P7);

}

void Game::draw_figures()
{
	for (auto piece : pieces)
	{
		piece->draw();
	}
}

void Game::draw_board()
{

}

void Game::update()
{
	// pobierz pozyc
}
