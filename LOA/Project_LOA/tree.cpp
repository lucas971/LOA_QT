#include "tree.h"

Tree::Tree()
{
    height = 0;
    width = 0;
    branches = std::vector<Branch>();
}

Tree::Tree(const Tree& tree)
{
    height = tree.height;
    width = tree.width;
    branches = std::vector<Branch>(tree.branches);
}

Tree::~Tree()
{

}
