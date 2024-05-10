#include "SFML_manager.h"

#include <iostream>
// --------------------------------------------------------------------------------------
// Inicjalizacja
// --------------------------------------------------------------------------------------
void SFML_manager::init()
{
	window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), APPNAME);
	window.setFramerateLimit(60);
}

void SFML_manager::update()
{
    mousePosition = sf::Mouse::getPosition(window);
}

void SFML_manager::setBrightnes(sf::Texture& texture, float factor)
{
    std::cout << "hej";
    // Pobierz rozmiar tekstury
    sf::Vector2u textureSize = texture.getSize();
   
    // Utwórz obiekt sf::Image, aby uzyskaæ dostêp do pikseli tekstury
    sf::Image image = texture.copyToImage();

    // PrzejdŸ przez ka¿dy piksel tekstury i przyciemnij go
    for (unsigned int y = 0; y < textureSize.y; ++y)
    {
        for (unsigned int x = 0; x < textureSize.x; ++x)
        {
            // Pobierz kolor piksela
            sf::Color pixel = image.getPixel(x, y);

            // Przyciemnij kolor piksela o podany czynnik
            pixel.r = 50;
            pixel.g = 9;
            pixel.b = 89;
    
            // Zapisz nowy kolor piksela
            image.setPixel(x, y, pixel);
        }
    }

    // Zapisz zmodyfikowane piksele z powrotem do tekstury
    texture.update(image);
}


