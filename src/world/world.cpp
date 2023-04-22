#include "world/world.hpp"

#include "elements/element.hpp"
#include "elements/empty.hpp"
#include "elements/elementFactory.hpp"

World::World(int width, int height)
{
    this->width = width;
    this->height = height;
    m_world = std::vector<std::vector<Element*> >(width, std::vector<Element*>(height));
    m_factory = new ElementFactory(this);

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

void World::createElementAtPosition(ElementType type, int x, int y)
{
    if (inBounds(x, y) && m_world[x][y] != nullptr)
    {
        delete m_world[x][y];
        m_world[x][y] = m_factory->create(type, x, y);
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
            setPreviousVisitedToFalse(i, j);
            tickElementIfNotVisited(i,j);
        }
    }
}

void World::setPreviousVisitedToFalse(int x, int y)
{
    if (inBounds(x, y - 1))
    {
        m_world[x][y - 1]->visited = false;
    }
}

void World::tickElementIfNotVisited(int x, int y)
{
    if (!(m_world[x][y]->visited))
    {
        m_world[x][y]->visited = true;
        m_world[x][y]->tick();
    }
}

