#include "branch.h"
#include "team.h"

Branch::Branch(){
    _team1 = Team();
    _team2 = Team();
    _finished = false;
    _winner = 0;
    _score1 = 0;
    _score2 = 0;
    return;
}

Branch::Branch(Team team1, Team team2, bool finished, int win, int s1, int s2){
    _team1 = team1;
    _team2 = team2;
    _finished = finished;
    _winner = win;
    _score1 = s1;
    _score2 = s2;
    return;
}

Branch::Branch(const Branch & branch){
    _team1 = branch._team1;
    _team2 = branch._team2;
    _finished = branch._finished;
    _winner = branch._winner;
    _score1 = branch._score1;
    _score2 = branch._score2;
    return;
}

Branch::~Branch(){

}
