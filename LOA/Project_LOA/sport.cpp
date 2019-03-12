#include "sport.h"
#include <string>

using namespace std;

int Sport::_sport_id=0;

Sport::Sport(){
    _id=_sport_id++;
    _sportname = "";
    _team = false;
    _teamCount = 1;
    return;
}

Sport::Sport(std::string sportname, bool team, int teamCount){
    _id=_sport_id++;
    _sportname = sportname;
    _team = team;
    _teamCount = teamCount;
    return;
}

Sport::Sport(const Sport & sport){
    _id=_sport_id++;
    _sportname = sport._sportname;
    _team = sport._team;
    _teamCount = sport._teamCount;
    return;
}

Sport::~Sport(){

}
