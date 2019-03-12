#ifndef TOURNAMENT_H
#define TOURNAMENT_H
#include <string>
#include <tree.h>
#include <sport.h>
#include <team.h>
#include <vector>

class Tournament
{
   int _id;
   static int _tourn_id;
   std::string _tournamentname;
   Sport _sport;
   std::string _password;
   int _roundCount;
   int _maxSub;
   int _sub;
   std::vector<Team> teams;
   Tree tournamenttree;

public:
   Tournament();
   Tournament(std::string name, Sport sport, std::string password, int roundCount, int maxSub, int sub, Team teams[], Tree tournamenttree);
   Tournament(const Tournament &);
   ~Tournament();

};

#endif // TOURNAMENT_H
