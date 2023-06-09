#pragma once

#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif


#include <stdio.h>
#include <iostream>

class Window
{
public:
    void create(const int &windowWidth, const int &windowHeight, const char * title, const Uint32 &flags);
    void destroy();
    SDL_Window*& getWindow(){ return mWindow; };

private:
    int mWindowWidth;
    int mWindowHeight;
    Uint32 mWindowFlags;
    SDL_Window * mWindow;
    SDL_GLContext mContext;
};