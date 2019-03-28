#ifndef TREE_H
#define TREE_H

#include <string>
#include <branch.h>
#include <QVector>

using namespace std;

class Tree
{
    int _height;
    int _width;
    QVector<Branch> _branches;

public:
   Tree();
   Tree(int h, int w, QVector<Branch> branches);
   Tree(const Tree &);
   ~Tree();

};


#endif // TREE_H
