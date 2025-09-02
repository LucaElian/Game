#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "lunarEngine.h"

class Game
{
public:
    Game(unsigned int width, unsigned int height, const char* title);
    void run();

private:
    //LunarEngine engine;
    sf::RenderWindow window;
};

#endif // GAME_H