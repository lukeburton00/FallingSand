#pragma once

#include "elements/element.hpp"
#include "elements/solid/sand.hpp"
#include "elements/solid/stone.hpp"
#include "elements/liquid/water.hpp"
#include "elements/liquid/lava.hpp"
#include "elements/gas/steam.hpp"

class World;
class ElementFactory
{
public:
    World* world;
    ElementFactory(World* world) : world(world){}
    Element* create(ElementType type, int x, int y)
    {
        switch(type)
        {
            case ElementType::EMPTY:
            {
                return new Empty(x, y, world);
                break;
            }

            case ElementType::SAND:
            {
                return new Sand(x, y, world);
                break;
            }

            case ElementType::STONE:
            {
                return new Stone(x, y, world);
                break;
            }

            case ElementType::WATER:
            {
                return new Water(x, y, world);
                break;
            }

            case ElementType::LAVA:
            {
                return new Lava(x, y, world);
                break;
            }

            case ElementType::STEAM:
            {
                return new Steam(x, y, world);
                break;
            }

            default:
            break;
        }
    }
};