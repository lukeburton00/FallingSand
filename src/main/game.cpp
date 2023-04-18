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
    int width = 800;
    int height = 800;
    const char * title = "Sand";
    Uint64 flags = SDL_WINDOW_RESIZABLE;

    window.create(width, height, title, flags);
    renderer.init(window.getWindow());

    world = new World(400, 400);

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

    if (Input::isKeyDown("S"))
    {
        world->setElementAtPosition<Sand>(mouseX, mouseY);
        world->setElementAtPosition<Sand>(mouseX + 1, mouseY);
        world->setElementAtPosition<Sand>(mouseX, mouseY + 1);
        world->setElementAtPosition<Sand>(mouseX + 1, mouseY + 1);
        world->setElementAtPosition<Sand>(mouseX - 1, mouseY);
        world->setElementAtPosition<Sand>(mouseX, mouseY - 1);
        world->setElementAtPosition<Sand>(mouseX - 1, mouseY - 1);
        world->setElementAtPosition<Sand>(mouseX + 1, mouseY - 1);
        world->setElementAtPosition<Sand>(mouseX - 1, mouseY + 1);
    }

    if (Input::isKeyDown("W"))
    {
        world->setElementAtPosition<Water>(mouseX, mouseY);
        world->setElementAtPosition<Water>(mouseX + 1, mouseY);
        world->setElementAtPosition<Water>(mouseX, mouseY + 1);
        world->setElementAtPosition<Water>(mouseX + 1, mouseY + 1);
        world->setElementAtPosition<Water>(mouseX - 1, mouseY);
        world->setElementAtPosition<Water>(mouseX, mouseY - 1);
        world->setElementAtPosition<Water>(mouseX - 1, mouseY - 1);
        world->setElementAtPosition<Water>(mouseX + 1, mouseY - 1);
        world->setElementAtPosition<Water>(mouseX - 1, mouseY + 1);
    }

    if (Input::isKeyDown("L"))
    {
        world->setElementAtPosition<Lava>(mouseX, mouseY);
        world->setElementAtPosition<Lava>(mouseX + 1, mouseY);
        world->setElementAtPosition<Lava>(mouseX, mouseY + 1);
        world->setElementAtPosition<Lava>(mouseX + 1, mouseY + 1);
        world->setElementAtPosition<Lava>(mouseX - 1, mouseY);
        world->setElementAtPosition<Lava>(mouseX, mouseY - 1);
        world->setElementAtPosition<Lava>(mouseX - 1, mouseY - 1);
        world->setElementAtPosition<Lava>(mouseX + 1, mouseY - 1);
        world->setElementAtPosition<Lava>(mouseX - 1, mouseY + 1);
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