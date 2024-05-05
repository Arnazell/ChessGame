#include "SFML_manager.h"
#include <optional>

// --------------------------------------------------------------------------------------
// Inicjalizacja
// --------------------------------------------------------------------------------------
void SFML_manager::init()
{
	window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), APPNAME);
	window.setFramerateLimit(60);
}


// --------------------------------------------------------------------------------------
// £adowanie tekstury
// --------------------------------------------------------------------------------------
void SFML_manager::loadTexture(const char* filename)
{
	
}
