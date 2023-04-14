#pragma once

#include <memory>

class World;

enum class ElementType
{
    EMPTY,
    SAND,
    WATER
};

class Element
{

public:
    int x, y;
    int id;
    ElementType type;

    Element(int x, int y, World* world)
    {
        this->x = x;
        this->y = y;
        
        this->world = world;
    }

    virtual ~Element() {}
    virtual void tick() = 0;

protected:
    World* world;
};