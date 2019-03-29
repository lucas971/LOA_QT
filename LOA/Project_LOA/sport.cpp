#include "sport.h"
#include <string>

int Sport::_sport_id=0;

Sport::Sport(){
    _id=_sport_id++;
    _sportname = "";
    return;
}

Sport::Sport(QString sportname){
    _id=_sport_id++;
    _sportname = sportname;
    return;
}

Sport::~Sport(){

}
