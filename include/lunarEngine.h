#ifndef LUNARENGINE_H
#define LUNARENGINE_H

#include <SFML/Graphics.hpp>

class LunarEngine
{
    public:
        LunarEngine();

        void render();
        void addObject();
        
        virtual void processEvents();
        virtual void update();
};

#endif