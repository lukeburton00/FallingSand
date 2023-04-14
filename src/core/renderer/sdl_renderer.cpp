#include "core/renderer/sdl_renderer.hpp"

void SDLRenderer::init(SDL_Window*& window)
{
    m_window = window;
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
}

SDLRenderer::~SDLRenderer()
{
    SDL_DestroyRenderer(m_renderer);
}

void SDLRenderer::drawRect(int x, int y, int width, int height, int red, int green, int blue, int alpha)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;

    SDL_RenderDrawRect(m_renderer, &rect);
    SDL_SetRenderDrawColor(m_renderer, red, green, blue, alpha);
    SDL_RenderFillRect(m_renderer, &rect);
}

void SDLRenderer::clear()
{
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);
}

void SDLRenderer::present()
{
    SDL_RenderPresent(m_renderer);
}