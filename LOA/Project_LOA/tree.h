#ifndef TREE_H
#define TREE_H
#include <string>
#include <branch.h>
#include <QVector>

class Tree
{


public:
   int _height;
   int _width;
   QVector<Branch> * _branches;
   Tree();
   Tree(int h, int w);
   Tree(const Tree &);
   Tree(int nTeams);
   ~Tree();

};

#endif // TREE_H
