#include "branch.h"
#include <string>
#include "team.h"

using namespace std;

Branch::Branch(){
    _team1 = Team::Team();
    _team2 = Team::Team();
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
    _team1 = team1;
    _team2 = team2;
    _finished = finished;
    _winner = win;
    _score1 = s1;
    _score2 = s2;
    return;
}

Branch::~Branch(){

}
