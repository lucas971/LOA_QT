#include "tournament.h"
#include "sport.h"
#include "team.h"
#include "tree.h"
#include <vector>
#include <string>

int Tournament::_tourn_id=0;

Tournament::Tournament(){
    _id=_tourn_id++;
    _tournamentname = "_";
    _sport = Sport();
    _password = "";
    _roundCount = 1;
    _maxSub = 2;
    _sub = 2;
    _teams = std::vector<Team>();
    _tournamenttree = Tree();
    return;
}


Tournament::Tournament(std::string name, Sport sport, std::string password, int roundCount, int maxSub, int sub, std::vector<Team> teams, Tree tournamenttree){
    _id=_tourn_id++;
    _tournamentname = name;
    _sport = sport;
    _password = password;
    _roundCount = roundCount;
    _maxSub = maxSub;
    _sub = sub;
    _teams = teams;
    _tournamenttree = tournamenttree;
    return;
}

Tournament::Tournament(const Tournament & tournament){
    _id=_tourn_id++;
    _tournamentname = tournament._tournamentname;
    _sport = tournament._sport;
    _password = tournament._password;
    _roundCount = tournament._roundCount;
    _maxSub = tournament._maxSub;
    _sub = tournament._sub;
    _teams = tournament._teams;
    _tournamenttree = tournament._tournamenttree;
    return;
}
