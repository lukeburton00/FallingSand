#pragma once

#include "elements/liquid/liquid.hpp"

#include "elements/solid/stone.hpp"
#include "elements/gas/steam.hpp"

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
        auto element = getElementToActOn();

        if (element != nullptr)
        {
            switch (element->type)
            {
                case ElementType::LAVA:
                {
                    world->setElementAtPosition<Steam>(x, y - 1);
                    world->setElementAtPosition<Empty>(element->x, element->y);
                    world->setElementAtPosition<Stone>(x, y);
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

        if (world->inBounds(x, y + 1) && (world->getElementAtPosition(x, y + 1)->type == ElementType::EMPTY || world->getElementAtPosition(x, y + 1)->type == ElementType::LAVA))
        {
            element = world->getElementAtPosition(x, y + 1);
        }

        else if (world->inBounds(x - 1, y + 1) && (world->getElementAtPosition(x - 1, y + 1)->type == ElementType::EMPTY || world->getElementAtPosition(x - 1, y + 1)->type == ElementType::LAVA))
        {
            element = world->getElementAtPosition(x - 1, y + 1);
        }

        else if (world->inBounds(x + 1, y + 1) && (world->getElementAtPosition(x + 1, y + 1)->type == ElementType::EMPTY || world->getElementAtPosition(x + 1, y + 1)->type == ElementType::LAVA))
        {
            element = world->getElementAtPosition(x + 1, y + 1);
        }

        else if (world->inBounds(x + 1, y) && (world->getElementAtPosition(x + 1, y)->type == ElementType::EMPTY || world->getElementAtPosition(x + 1, y)->type == ElementType::LAVA))
        {
            element = world->getElementAtPosition(x + 1, y);
        }

        else if (world->inBounds(x - 1, y) && (world->getElementAtPosition(x - 1, y)->type == ElementType::EMPTY || world->getElementAtPosition(x - 1, y)->type == ElementType::LAVA))
        {
            element = world->getElementAtPosition(x - 1, y);
        }

        return element;
    }
};