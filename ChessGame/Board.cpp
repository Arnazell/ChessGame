#include "Board.h"
#include <iostream>

#define tileSize 128

Board::Board(SFML_manager* graphics)
    : graphics(graphics), check(false)
{
    //Inicjalizacja pustej planszy
    for (auto field : board_state)
    {
        field = nullptr;
    }

    // inicjacja zajetych pol
    for (int field : white_fields)
    {
        field = 0;
    }
    for (int field : black_fields)
    {
        field = 0;
    }
    // Rysowanie pustej planszy
}

void Board::drawBoard()
{
    bool isWhite = true;
    for (int i = 0; i < 8; ++i) 
    {
        isWhite = !isWhite;
        for (int j = 0; j < 8; ++j) 
        {
            sf::RectangleShape tile(sf::Vector2f(tileSize, tileSize));
            tile.setPosition(j * tileSize, i * tileSize);

            if (isWhite) 
            {
                tile.setFillColor(sf::Color(255, 206, 158)); // bia³e pole
            }
            else 
            {
                tile.setFillColor(sf::Color(209, 139, 71)); // czarne pole
            }

            isWhite = !isWhite;
            graphics->window.draw(tile);
        }
    }
}

void Board::drawFields()
{
    std::cout << "White:\n";
    
    for (int j = 0; j < 8; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            std::cout << white_fields[i + j * 8] << " ";
        }
        std::cout << "\n";

    }

    std::cout << "Black:\n";

    for (int j = 0; j < 8; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            std::cout << black_fields[i + j * 8] << " ";
        }
        std::cout << "\n";

    }
}

bool Board::check_check()
{
    // przeszukaj kazde atakowane pola bialego gracza
    for (int j = 0; j < 8; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            if (white_fields[i + j * 8] != 0)
            {
                if (board_state[i + j * 8])
                {
                    if (board_state[i + j * 8]->m_type == KING)
                    {
                        return true;
                    }
                }
            }
        }
    }

    // przeszukaj kazde atakowane pola bialego gracza
    for (int j = 0; j < 8; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            if (black_fields[i + j * 8] != 0)
            {
                if (board_state[i + j * 8])
                {
                    if (board_state[i + j * 8]->m_type == KING)
                    {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}
