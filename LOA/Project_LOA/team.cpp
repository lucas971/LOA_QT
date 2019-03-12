#include "team.h"
#include "player.h"
#include <string>

using namespace std;

int Team::_team_id=0;

Team::Team(){
    _id=_team_id++;
    _count=1;
    _teamName="";
    _website="";
    _members.push_back(Player());
    return;
}

Team::Team(int count, string name, string website, std::vector<Player> members){
    _id=_team_id++;
    _count=count;
    _teamName=name;
    _website=website;
    _members=members;
    return;
}

Team::Team(const Team &){

}

Team::~Team(){

}
