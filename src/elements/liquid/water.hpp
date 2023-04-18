#pragma once

#include "elements/liquid/liquid.hpp"

class Water : public Liquid
{
public:
    using Liquid::Liquid;

    Water(int x, int y, World* world) : Liquid(x, y, world)
    {
        type = ElementType::WATER;
    }

    void tick() override
    {

        if (world->inBounds(x, y + 1) && world->getElementAtPosition(x, y + 1)->type == ElementType::EMPTY)
        {
            moveAndSwap(x, y + 1);
        }

        else if (world->inBounds(x - 1, y + 1) && world->getElementAtPosition(x - 1, y + 1)->type == ElementType::EMPTY)
        {
            moveAndSwap(x - 1, y + 1);
        }

        else if (world->inBounds(x + 1, y + 1) &&  world->getElementAtPosition(x + 1, y + 1)->type == ElementType::EMPTY)
        {
            moveAndSwap(x + 1, y + 1);
        }

        else if (world->inBounds(x + 1, y) &&  world->getElementAtPosition(x + 1, y)->type == ElementType::EMPTY)
        {
            moveAndSwap(x + 1, y);
        }

        else if (world->inBounds(x - 1, y) &&  world->getElementAtPosition(x - 1, y)->type == ElementType::EMPTY)
        {
            moveAndSwap(x - 1, y);
        }
    }
};