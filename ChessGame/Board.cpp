#include "Board.h"


#define tileSize 128

Board::Board(SFML_manager* graphics)
    : graphics(graphics)
{
    //Inicjalizacja pustej planszy
    for (auto field : board_state)
    {
        field = nullptr;
    }

    // Rysowanie pustej planszy
}

void Board::drawBoard()
{
    bool isWhite = true;
    for (int i = 0; i < 8; ++i) {
        isWhite = !isWhite;
        for (int j = 0; j < 8; ++j) {
            sf::RectangleShape tile(sf::Vector2f(tileSize, tileSize));
            tile.setPosition(j * tileSize, i * tileSize);

            if (isWhite) {
                tile.setFillColor(sf::Color(255, 206, 158)); // bia³e pole
            }
            else {
                tile.setFillColor(sf::Color(209, 139, 71)); // czarne pole
            }

            isWhite = !isWhite;
            graphics->window.draw(tile);
        }
    }
}
