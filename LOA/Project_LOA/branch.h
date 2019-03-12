#ifndef BRANCH_H
#define BRANCH_H

#include <string>
#include <team.h>

using namespace std;

class Branch
{
    Team _team1;
    Team _team2;
    bool _finished;
    int _winner;
    int _score1;
    int _score2;

public:
    Branch();
    Branch(const Branch &);
    ~Branch();

};


#endif // BRANCH_H
