#pragma once

#include "core/window/window.hpp"
#include "core/renderer/sdl_renderer.hpp"

class World;
class Game
{
public:
    Game();
    void start();

    ~Game();

private:
    Window window;
    SDLRenderer renderer;
    std::unique_ptr<World> world;
    bool isRunning;
    float cellScaleX, cellScaleY;

    void run();
    void processInput();
    void update();
    void render();
    void shutdown();
};