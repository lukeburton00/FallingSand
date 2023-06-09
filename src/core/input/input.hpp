#pragma once

#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include <vector>

class Input
{
public:
	static bool quit;

	static void processInput();

	static bool isKeyPressed(const char * key);
	static bool isKeyReleased(const char * key);
	static bool isKeyDown(const char * key);

	static bool isLeftMouseButtonPressed();
	static bool isRightMouseButtonPressed();

	static bool isLeftMouseButtonDown();
	static bool isRightMouseButtonDown();

	static int mousePositionX, mousePositionY;

private:
	static bool leftMouseButtonDown;
	static bool rightMouseButtonDown;

	static bool leftMouseButtonPressed;
	static bool rightMouseButtonPressed;
	
	static std::vector<SDL_Keycode> pressedKeys;	
	static std::vector<SDL_Keycode> releasedKeys;
	static std::vector<SDL_Keycode> downKeys;
};