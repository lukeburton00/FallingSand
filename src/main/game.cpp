#include "main/game.hpp"

#include "core/input/input.hpp"
#include "elements/solid/sand.hpp"
#include "elements/liquid/water.hpp"
#include "world/world.hpp"

Game::Game()
{
    int width = 800;
    int height = 600;
    const char * title = "Sand";
    Uint64 flags = SDL_WINDOW_RESIZABLE;

    window.create(width, height, title, flags);
    renderer.init(window.getWindow());

    world = new World(80, 60);
}

Game::~Game()
{
    delete world;
}

void Game::start()
{
    run();
}

void Game::run()
{
    isRunning = true;
    while(isRunning)
    {
        processInput();
        update();
        render();
    }

    shutdown();
}

void Game::processInput()
{
    Input::processInput();
    if (Input::quit) { isRunning = false; }
    if (Input::isKeyPressed("Escape" )) { isRunning = false; }
}

void Game::update()
{
    int mouseX = Input::mousePositionX / 10;
    int mouseY = Input::mousePositionY / 10;

    if (Input::isLeftMouseButtonDown())
    {
        world->setElementAtPosition<Sand>(mouseX, mouseY);
    }

    if (Input::isRightMouseButtonDown())
    {
        world->setElementAtPosition<Empty>(mouseX, mouseY);
    }

    world->tickAllElements();
}

void Game::render()
{
    renderer.clear();

    for (int i = 0; i < world->width; i++)
    {
        for (int j = 0; j < world->height; j++)
        {
            auto element = world->getElementAtPosition(i, j);

            if (element->type == ElementType::SAND)
            {
                renderer.drawRect(element->x * 10, element->y * 10, 10, 10, 255,255,0,255);  
            }
        }
    }

    renderer.present();
}

void Game::shutdown()
{
    window.destroy();
}