#pragma once

#include <vector>
#include <iostream>

class Element;
class World
{
public:
    int width, height;

    World(int width, int height);
    ~World();

    Element* getElementAtPosition(int x, int y);
    void setElementAtPosition(int x, int y, Element* element);

    template <typename T>
    void setElementAtPosition(int x, int y)
    {
        if (inBounds(x, y))
        {
            delete m_world[x][y];
            m_world[x][y] = new T(x, y, this);
        }
    }

    void tickAllElements();

    bool inBounds(int x, int y);

private:
    std::vector<std::vector<Element*> > m_world;
};