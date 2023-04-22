#pragma once

#include "elements/liquid/liquid.hpp"

#include "elements/solid/stone.hpp"
#include "elements/gas/steam.hpp"

class Lava : public Liquid
{
public:
    using Liquid::Liquid;

    Lava(int x, int y, World* world) : Liquid(x, y, world)
    {
        type = ElementType::LAVA;
        density = 0.5f;
    }

    void tick() override
    {
        auto element = getElementToActOn();

        if (element != nullptr)
        {
            switch (element->type)
            {
                case ElementType::WATER:
                {
                    world->createElementAtPosition(ElementType::STEAM, x, y - 1);
                    world->createElementAtPosition(ElementType::STONE, element->x, element->y);
                    world->createElementAtPosition(ElementType::EMPTY, x, y);

                    break;
                }

                
                case ElementType::EMPTY:
                {
                    moveAndSwap(element->x, element->y);
                    break;
                }

                default:
                    break;
            }

        }
    }

    Element* getElementToActOn()
    {
        Element* element = nullptr;

        if (world->inBounds(x, y + 1) && (world->getElementAtPosition(x, y + 1)->density < density))
        {
            element = world->getElementAtPosition(x, y + 1);
        }

        else if (world->inBounds(x - 1, y + 1) && (world->getElementAtPosition(x - 1, y + 1)->density < density))
        {
            element = world->getElementAtPosition(x - 1, y + 1);
        }

        else if (world->inBounds(x + 1, y + 1) && (world->getElementAtPosition(x + 1, y + 1)->density < density))
        {
            element = world->getElementAtPosition(x + 1, y + 1);
        }

        else if (world->inBounds(x + 1, y) && (world->getElementAtPosition(x + 1, y)->density < density))
        {
            element = world->getElementAtPosition(x + 1, y);
        }

        else if (world->inBounds(x - 1, y) && (world->getElementAtPosition(x - 1, y)->density < density))
        {
            element = world->getElementAtPosition(x - 1, y);
        }

        return element;
    }
};