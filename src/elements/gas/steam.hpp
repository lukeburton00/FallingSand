#pragma once

#include "elements/gas/gas.hpp"

class Steam : public Gas
{
public:
    using Gas::Gas;
    float lifetime;

    Steam(int x, int y, World* world) : Gas(x, y, world)
    {
        type = ElementType::STEAM;
        density = -0.1f;
        lifetime = 2000.0f + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(500.0f-2000.0f)));
    }

    void tick() override
    {
        auto element = getElementToActOn();

        if (element != nullptr)
        {
            moveAndSwap(element->x, element->y);
        }

        if (lifetime < 0.0f)
        {
            world->createElementAtPosition(ElementType::EMPTY, x, y);
            return;
        }

        lifetime -= 10.0f;
    }

    Element* getElementToActOn()
    {
        Element* element = nullptr;

        if (world->inBounds(x, y - 1) && world->getElementAtPosition(x, y - 1)->density > density)
        {
            element = world->getElementAtPosition(x, y - 1);
        }

        else if (world->inBounds(x - 1, y) && world->getElementAtPosition(x - 1, y)->density > density)
        {
            element = world->getElementAtPosition(x - 1, y);
        }

        else if (world->inBounds(x + 1, y) && world->getElementAtPosition(x + 1, y)->density > density)
        {
            element = world->getElementAtPosition(x + 1, y);
        }

        else if (world->inBounds(x + 1, y - 1) && world->getElementAtPosition(x + 1, y - 1)->density > density)
        {
            element = world->getElementAtPosition(x + 1, y - 1);
        }

        else if (world->inBounds(x - 1, y - 1) && world->getElementAtPosition(x - 1, y - 1)->density > density)
        {
            element = world->getElementAtPosition(x - 1, y - 1);
        }

        return element;
    }
};