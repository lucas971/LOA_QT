#ifndef BRANCH_H
#define BRANCH_H

#include "team.h"

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
    Branch(Team team1, Team team2, bool finished, int win, int s1, int s2);
    Branch(const Branch & branch);
    ~Branch();

};


#endif // BRANCH_H
