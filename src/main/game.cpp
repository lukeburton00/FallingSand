#include "main/game.hpp"

#include "core/input/input.hpp"
#include "world/world.hpp"

#include "elements/solid/sand.hpp"
#include "elements/solid/stone.hpp"
#include "elements/liquid/water.hpp"
#include "elements/liquid/lava.hpp"
#include "elements/gas/steam.hpp"

Game::Game()
{
    int width = 768;
    int height = 768;
    const char * title = "Sand";
    Uint32 flags = SDL_WINDOW_RESIZABLE;

    window.create(width, height, title, flags);
    renderer.init(window.getWindow());

    world = std::make_unique<World>(256, 256);

    cellScaleX = width / world->width;
    cellScaleY = height / world->height;
}

Game::~Game()
{

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

    if (Input::isKeyDown("S"))
    {
        world->createElementAtPosition(ElementType::SAND, mouseX, mouseY);
    }

    if (Input::isKeyDown("W"))
    {
        world->createElementAtPosition(ElementType::WATER, mouseX, mouseY);
    }

    if (Input::isKeyDown("L"))
    {
        world->createElementAtPosition(ElementType::LAVA, mouseX, mouseY);
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

            else if (element->type == ElementType::STONE)
            {
                renderer.drawRect(element->x * cellScaleX, element->y * cellScaleY, cellScaleX, cellScaleY, 100,100,100,255);  
            }

            else if (element->type == ElementType::LAVA)
            {
                renderer.drawRect(element->x * cellScaleX, element->y * cellScaleY, cellScaleX, cellScaleY, 255,0,0,255);  
            }

            else if (element->type == ElementType::STEAM)
            {
                renderer.drawRect(element->x * cellScaleX, element->y * cellScaleY, cellScaleX, cellScaleY, 200,200,200,255);  
            }
        }
    }

    renderer.present();
}

void Game::shutdown()
{
    window.destroy();
}
