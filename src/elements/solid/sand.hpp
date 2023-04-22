#pragma once

#include "elements/solid/solid.hpp"

#include "elements/liquid/liquid.hpp"
#include "elements/empty.hpp"
#include "world/world.hpp"

#include <memory>

class Sand : public Solid
{
public:
    using Solid::Solid;

    Sand(int x, int y, World* world) : Solid(x, y, world)
    {
        type = ElementType::SAND;
        density = 0.8f;
    }

    void tick() override
    {
        if (world->inBounds(x, y + 1) && (world->getElementAtPosition(x, y + 1)->density < density))
        {
            moveAndSwap(x, y + 1);
        }

        else if (world->inBounds(x - 1, y + 1) && (world->getElementAtPosition(x - 1, y + 1)->density < density))
        {

            moveAndSwap(x - 1, y + 1);
        }

        else if (world->inBounds(x + 1, y + 1) &&  (world->getElementAtPosition(x + 1, y + 1)->density < density))
        {
            moveAndSwap(x + 1, y + 1);
        }
    }
};