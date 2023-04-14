#pragma once

#include "element.hpp"

class Empty : public Element
{
public:
    using Element::Element;

    Empty(int x, int y, World* world) : Element(x, y, world)
    {
        type = ElementType::EMPTY;
    }

    void tick() override{}
};