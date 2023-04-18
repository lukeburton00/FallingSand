#include "main/game.hpp"

#include "core/input/input.hpp"
#include "elements/solid/sand.hpp"
#include "elements/liquid/water.hpp"
#include "world/world.hpp"

Game::Game()
{
    int width = 768;
    int height = 768;
    const char * title = "Sand";
    Uint64 flags = SDL_WINDOW_RESIZABLE;

    window.create(width, height, title, flags);
    renderer.init(window.getWindow());

    world = new World(256, 256);

    cellScaleX = width / world->width;
    cellScaleY = height / world->height;
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
    int mouseX = Input::mousePositionX / cellScaleX;
    int mouseY = Input::mousePositionY / cellScaleY;

    if (Input::isLeftMouseButtonDown())
    {
        world->setElementAtPosition<Sand>(mouseX, mouseY);
    }

    if (Input::isRightMouseButtonDown())
    {
        world->setElementAtPosition<Water>(mouseX, mouseY);
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
                renderer.drawRect(element->x * cellScaleX, element->y * cellScaleY, cellScaleX, cellScaleY, 255,255,0,255);  
            }

            else if (element->type == ElementType::WATER)
            {
                renderer.drawRect(element->x * cellScaleX, element->y * cellScaleY, cellScaleX, cellScaleY, 0,0,255,255);  
            }
        }
    }

    renderer.present();
}

void Game::shutdown()
{
    window.destroy();
}