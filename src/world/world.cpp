#include "world/world.hpp"

#include "elements/element.hpp"
#include "elements/empty.hpp"

World::World(int width, int height)
{
    this->width = width;
    this->height = height;
    m_world = std::vector<std::vector<std::shared_ptr<Element>> >(width, std::vector<std::shared_ptr<Element>>(height));
    m_buffer = std::vector<std::vector<std::shared_ptr<Element>> >(width, std::vector<std::shared_ptr<Element>>(height));

    for (int i = 0; i < m_world.size(); ++i)
    {
        for (int j = 0; j < m_world[i].size(); ++j)
        {
            m_world.at(i).at(j) = std::make_shared<Empty>(i, j, this);
        }
    }

    m_buffer = m_world;
}

World::~World()
{
    // for (int i = 0; i < m_world.size(); ++i)
    // {
    //     for (int j = 0; j < m_world[i].size(); ++j)
    //     {
    //         if (m_world[i][j]->type != ElementType::EMPTY)
    //         {
    //             printf(" %d, %d\n", m_world[i][j]->x, m_world[i][j]->y);
    //         }
    //     }
    // }
}

std::shared_ptr<Element> World::getElementAtPosition(int x, int y)
{
    return m_world.at(x).at(y);
}

void World::tickAllElements()
{
    for (int i = 0; i < m_world.size(); ++i)
    {
        for (int j = 0; j < m_world[i].size(); ++j)
        {
            if (m_world[i][j]->type != ElementType::EMPTY)
            {
                m_world[i][j]->tick();
            }
        }
    }
    m_world = m_buffer;
}

