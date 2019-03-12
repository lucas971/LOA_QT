#ifndef TREE_H
#define TREE_H

#include <string>
#include <branch.h>
#include <vector>

using namespace std;

class Tree
{
    int height;
    int width;
    std::vector<Branch> branches;

public:
   Tree();
   Tree(const Tree &);
   ~Tree();

};


#endif // TREE_H
