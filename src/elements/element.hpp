#pragma once

#include "world/world.hpp"

#include <memory>

class Element
{

public:
    int x, y;
    int id;
    float density;
    bool visited;
    ElementType type{};

    Element(int x, int y, World* world)
    {
        this->x = x;
        this->y = y;
        
        this->world = world;
        visited = false;
    }

    void moveAndSwap(int x, int y)
    {
        if (world->inBounds(x, y))
        {
            auto temp = world->getElementAtPosition(x,y);
            temp->x = this->x, temp->y = this->y;

            world->setElementAtPosition(x, y, this);
            world->setElementAtPosition(this->x, this->y, temp);

            this->x = x;
            this->y = y;
        }
    }

    virtual ~Element() {}
    virtual void tick() = 0;

protected:
    World* world;
};