#pragma once

#include <vector>
#include <iostream>

enum class ElementType : int
{
    EMPTY,
    SAND,
    WATER,
    STONE,
    LAVA,
    STEAM
};

class Element;
class ElementFactory;
class World
{
public:
    int width, height;

    World(int width, int height);
    ~World();

    Element* getElementAtPosition(int x, int y);

    void setElementAtPosition(int x, int y, Element* element);
    void createElementAtPosition(ElementType type, int x, int y);

    void tickAllElements();
    bool inBounds(int x, int y);

private:
    std::vector<std::vector<Element*> > m_world;
    ElementFactory* m_factory;

    void setPreviousVisitedToFalse(int x, int y);
    void tickElementIfNotVisited(int x, int y);

};