#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <optional>

// --------------------------------------------------------------------------------------
// Klasa zarz�dzaj�ca grafik� - generuje okna, �aduje pliki, 
// --------------------------------------------------------------------------------------

class SFML_manager
{
public:
	// Screen seetings
	const int SCREEN_WIDTH = 1024;
	const int SCREEN_HEIGHT = 1024;
	const char* APPNAME = "Chess2024";

	// Framerate
	const int MAX_FPS = 60;

	//  Okno 
	sf::RenderWindow window;

	// Inicjalizuje okno
	void init();

};
