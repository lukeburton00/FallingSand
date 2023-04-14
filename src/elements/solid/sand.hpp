#pragma once

#include "elements/solid/solid.hpp"
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
    }

    void tick() override
    {
        if (y == world->height - 1) return;

        if (world->inBounds(x, y+1) && world->getElementAtPosition(x, y + 1)->type == ElementType::EMPTY)
        {
            world->setElementAtPosition<Sand>(x, y + 1);
            world->setElementAtPosition<Empty>(x, y);
            y++;
            return;
        }

        if (world->inBounds(x - 1, y + 1) && world->getElementAtPosition(x - 1, y + 1)->type == ElementType::EMPTY)
        {
            world->setElementAtPosition<Sand>(x - 1, y + 1);
            world->setElementAtPosition<Empty>(x, y);
            x--;
            y++;
            return;
        }

        if (world->inBounds(x + 1, y + 1) &&  world->getElementAtPosition(x + 1, y + 1)->type == ElementType::EMPTY)
        {
            world->setElementAtPosition<Sand>(x + 1, y + 1);
            world->setElementAtPosition<Empty>(x, y);
            x++;
            y++;
            return;
        }
    }
};