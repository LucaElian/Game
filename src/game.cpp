#include <iostream>
#include "game.h"
#include <SFML/Graphics.hpp>

using namespace std;

Game::Game(unsigned int width, unsigned int height, const char* title) 
    : window(sf::VideoMode({width, height}), title)
{
    cout << width << height << title << endl;
}

void Game::run()
{
    while (window.isOpen())
    {
        // Procesa eventos
        while (const std::optional event = window.pollEvent())
        {
            // Si cierra la ventana se cierra la ventana
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        
        // Clear, draw, display, etc
        window.clear();
        // engine.render();
        window.display();
    }
}