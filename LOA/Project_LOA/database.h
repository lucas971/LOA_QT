#ifndef DATABASE_H
#define DATABASE_H
#include "player.h"
#include "team.h"
#include "tournament.h"
#include <QModelIndex>
class Database
{

public:
   Database();
   ~Database();

   QMap<int, Player> players;
   QMap<int, Team> teams;
   QMap<int, Tournament> tournaments;


};
#endif // DATABASE_H
