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
        // TODO: implement water logic here
    }
};