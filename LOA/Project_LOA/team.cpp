#include "team.h"
#include "player.h"
#include <string>

int Team::_team_id=0;

Team::Team(){
    _id=_team_id++;
    _count=1;
    _teamName="";
    _website="";
    return;
}

Team::Team(int count, QString name, QString website){
    _id=_team_id++;
    _count=count;
    _teamName=name;
    _website=website;
    _members=new QVector<Player>(count);
    return;
}

Team::Team(const Team & team){
    _id=team._id;
    _count=team._count;
    _teamName=team._teamName;
    _website=team._website;
    _members=team._members;
    return;
}

Team::~Team(){
}
