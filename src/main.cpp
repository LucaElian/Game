#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "game.h"

int main()
{
    Game game(800, 600, "CGame - SFML");
    game.run();
    return 0;
}