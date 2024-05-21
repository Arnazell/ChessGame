#include "Assets.h"
#include <stdexcept>

Assets::Assets()
{
}

void Assets::init()
{
	textureLoad();
	audioLoad();
}

// OBSLUGA £ADOWANIA
class TextureLoadError : public std::runtime_error
{
public:
	TextureLoadError(const std::string& message) : std::runtime_error(message) {}
};

void Assets::textureLoad() 
{
	try
	{
		// ladowanie tekstury pionka 
		texture_pawn_white.loadFromFile("Res/white-pawn.png");
		if (texture_pawn_white.getSize() == sf::Vector2u(0, 0))
		{
			throw TextureLoadError("Error loading texture: white-pawn.png");
		}

		// ladowanie tekstury pionka 
		texture_pawn_black.loadFromFile("Res/black-pawn.jpg");
		if (texture_pawn_black.getSize() == sf::Vector2u(0, 0))
		{
			throw TextureLoadError("Error loading texture: black-pawn.png");
		}

		// ladowanie tekstury wiezy 
		texture_rook_white.loadFromFile("Res/white-rook.png");
		if (texture_rook_white.getSize() == sf::Vector2u(0, 0))
		{
			throw TextureLoadError("Error loading texture: white-rook.png");
		}
		// ladowanie tekstury wiezy 
		texture_rook_black.loadFromFile("Res/black-rook.png");
		if (texture_rook_black.getSize() == sf::Vector2u(0, 0))
		{
			throw TextureLoadError("Error loading texture: black-rook.png");
		}

		// ladowanie tekstury konia 
		texture_knight_white.loadFromFile("Res/white-knight.png");
		if (texture_knight_white.getSize() == sf::Vector2u(0, 0))
		{
			throw TextureLoadError("Error loading texture: white-knight.png");
		}

		// ladowanie tekstury konia 
		texture_knight_black.loadFromFile("Res/black-knight.png");
		if (texture_knight_black.getSize() == sf::Vector2u(0, 0))
		{
			throw TextureLoadError("Error loading texture: black-knight.png");
		}

		// ladowanie tekstury goñæa
		texture_bishop_white.loadFromFile("Res/white-bishop.png");
		if (texture_bishop_white.getSize() == sf::Vector2u(0, 0))
		{
			throw TextureLoadError("Error loading texture:white-bishop.png");
		}

		// ladowanie tekstury goñæa
		texture_bishop_black.loadFromFile("Res/black-bishop.png");
		if (texture_bishop_black.getSize() == sf::Vector2u(0, 0))
		{
			throw TextureLoadError("Error loading texture: black-bishop.png");
		}

		// ladowanie tekstury krolowej
		texture_queen_white.loadFromFile("Res/white-queen.png");
		if (texture_queen_white.getSize() == sf::Vector2u(0, 0))
		{
			throw TextureLoadError("Error loading texture: black-queen.png");
		}

		// ladowanie tekstury krolowej
		texture_queen_black.loadFromFile("Res/black-queen.png");
		if (texture_queen_black.getSize() == sf::Vector2u(0, 0))
		{
			throw TextureLoadError("Error loading texture: black-queen.png");
		}

		// ladowanie tekstury krola
		texture_king_white.loadFromFile("Res/white-king.png");
		if (texture_king_white.getSize() == sf::Vector2u(0, 0))
		{
			throw TextureLoadError("Error loading texture: black-king.png");
		}
		/// ladowanie tekstury krola
		texture_king_black.loadFromFile("Res/black-king.png");
		if (texture_king_black.getSize() == sf::Vector2u(0, 0))
		{
			throw TextureLoadError("Error loading texture: black-king.png");
		}
	}
	catch (const TextureLoadError& e)
	{
		// Obs³u¿ wyj¹tek TextureLoadError
		std::cout << "Texture load error: " << e.what() << std::endl;

		// drastyczne ale dla celow pokazowych uzyteczne
		exit(0);
	}

}

void Assets::audioLoad()
{
	end_of_the_game_song.openFromFile("Res/sound01.mp3");
}
