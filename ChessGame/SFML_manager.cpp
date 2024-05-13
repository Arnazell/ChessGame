#include "SFML_manager.h"


#include <iostream>
// --------------------------------------------------------------------------------------
// Inicjalizacja
// --------------------------------------------------------------------------------------
void SFML_manager::init()
{
	window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), APPNAME);
	window.setFramerateLimit(60);
    LPMblocked = false;
}

void SFML_manager::update()
{
    mousePosition = sf::Mouse::getPosition(window);
    mousePressedLPM = sf::Mouse::isButtonPressed(sf::Mouse::Left);

    // Jesli mysz jest kliknieta
    if (mousePressedLPM)
    {
        // Gdy nie bylo wczesniej klikniecie
        if (!LPMblocked)
        {
            LPMclick = true;
            LPMblocked = true;
        }
        else LPMclick = false;
    }
    else
    {
        LPMclick = false;
        LPMblocked = false;
    }
        
}

void SFML_manager::setBrightnes(sf::Texture& texture, float factor)
{
    std::cout << "hej";
    // Pobierz rozmiar tekstury
    sf::Vector2u textureSize = texture.getSize();
   
    // Utw�rz obiekt sf::Image, aby uzyska� dost�p do pikseli tekstury
    sf::Image image = texture.copyToImage();

    // Przejd� przez ka�dy piksel tekstury i przyciemnij go
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

void SFML_manager::playMusic(sf::Music &sound)
{
    // Odtw�rz d�wi�k
    sound.play();

    // P�tla programu, aby utrzyma� d�wi�k w odtwarzaczu
    while (sound.getStatus() == sf::Music::Playing)
    {
        // Pauza na chwil�, aby unikn�� przeci��enia procesora
        sf::sleep(sf::milliseconds(100));
    }
}


