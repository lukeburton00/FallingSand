#pragma once

#include "elements/element.hpp"

#include <vector>
#include <iostream>

class World
{
public:
    int width, height;

    World(int width, int height);
    ~World();

    std::shared_ptr<Element> getElementAtPosition(int x, int y);

    template <typename T>
    void setElementAtPosition(int x, int y)
    {
        if (inBounds(x, y))
        {
            m_buffer.at(x).at(y) = std::make_shared<T>(x, y, this);
        }
    }

    void tickAllElements();

    bool inBounds(int x, int y)
    {
        if (x < 0 || y < 0 || x >= width || y >= height) return false;

        return true;
    }

private:
    std::vector<std::vector<std::shared_ptr<Element>> > m_world;
    std::vector<std::vector<std::shared_ptr<Element>> > m_buffer;


};