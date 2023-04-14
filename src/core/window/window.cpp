#include "core/window/window.hpp"

void Window::create(const int &windowWidth, const int &windowHeight, const char * title, const Uint32 &flags)
{
    #ifdef DEBUG
    printf("Creating window...\n");
    #endif

    mWindowWidth = windowWidth;
    mWindowHeight = windowHeight;
    mWindowFlags = flags;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL video could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }

    else
    {
        mWindow = SDL_CreateWindow( title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mWindowWidth, mWindowHeight, mWindowFlags);
        if( mWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            return;
        }
    }

    #ifdef DEBUG
    printf("Window created.\n");
    #endif
}

void Window::destroy()
{
    #ifdef DEBUG
    printf("\nDestroying Window...\n");
    #endif
    
    SDL_DestroyWindow(mWindow);

    #ifdef DEBUG
    printf("Window destroyed.\n");
    #endif
}