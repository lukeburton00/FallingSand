#include "world/world.hpp"

#include "elements/element.hpp"
#include "elements/empty.hpp"

World::World(int width, int height)
{
    this->width = width;
    this->height = height;
    m_world = std::vector<std::vector<Element*> >(width, std::vector<Element*>(height));

    for (int i = 0; i < m_world.size(); ++i)
    {
        for (int j = 0; j < m_world[i].size(); ++j)
        {
            m_world[i][j] = new Empty(i, j, this);
        }
    }
}

World::~World()
{
    for (int i = 0; i < m_world.size(); ++i)
    {
        for (int j = 0; j < m_world[i].size(); ++j)
        {
            delete m_world[i][j];
        }
    }
}

Element* World::getElementAtPosition(int x, int y)
{
    return m_world[x][y];
}

void World::setElementAtPosition(int x, int y, Element* element)
    {
        if (inBounds(x, y))
        {
            m_world[x][y] = element;
        }
    }

bool World::inBounds(int x, int y)
{
    if (x < 0 || y < 0 || x >= width || y >= height) return false;

    return true;
}

void World::tickAllElements()
{
    for (int i = 0; i < m_world.size(); ++i)
    {
        for (int j = 0; j < m_world[i].size(); ++j)
        {
            m_world[i][j]->visited = false;
        }
    }

    for (int i = 0; i < m_world.size(); ++i)
    {
        for (int j = 0; j < m_world[i].size(); ++j)
        {
            if (!(m_world[i][j]->visited))
            {
                m_world[i][j]->visited = true;
                m_world[i][j]->tick();
            }
        }
    }
}

