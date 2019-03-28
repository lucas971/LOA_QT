#include "tree.h"

Tree::Tree()
{
    _height = 0;
    _width = 0;
    _branches = QVector<Branch>();
}

Tree::Tree(int h, int w, QVector<Branch> branches)
{
    _height = h;
    _width = w;
    _branches = branches;
}

Tree::Tree(const Tree& tree)
{
    _height = tree._height;
    _width = tree._width;
    _branches = QVector<Branch>(tree._branches);
}

Tree::~Tree()
{
    delete this;
}
