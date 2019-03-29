#include "tree.h"
Tree::Tree()
{
    _height = 0;
    _width = 0;
}

Tree::Tree(int h, int w)
{
    _height = h;
    _width = w;
}

Tree::Tree(const Tree& tree)
{
    _height = tree._height;
    _width = tree._width;
    _branches = tree._branches;
}

Tree::Tree(int nTeam){
    _height = nTeam/4;
    _width = nTeam/4;
}
Tree::~Tree()
{
    delete this;
}
