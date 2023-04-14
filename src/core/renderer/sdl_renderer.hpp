#pragma once

#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

class SDLRenderer
{
public:
    SDLRenderer() = default;
    ~SDLRenderer();
    void init(SDL_Window*& window);

    void drawRect(int x, int y, int width, int height, int red, int green, int blue, int alpha);

    void clear();
    void present();

private:
    SDL_Renderer* m_renderer;
    SDL_Window* m_window;
};