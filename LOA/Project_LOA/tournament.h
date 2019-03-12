#ifndef TOURNAMENT_H
#define TOURNAMENT_H
#include <string>
#include <tree.h>
#include <sport.h>
#include <team.h>
#include <vector>

using namespace std;

class Tournament
{
   int _id;
   static int _tourn_id;
   string _tournamentname;
   Sport _sport;
   string _password;
   int _roundCount;
   int _maxSub;
   int _sub;
   std::vector<Team> teams;
   Tree tournamenttree;

public:
   Tournament();
   Tournament(string name, Sport sport, string password, int roundCount, int maxSub, int sub, Team teams[], Tree tournamenttree);
   Tournament(const Tournament &);
   ~Tournament();

};

#endif // TOURNAMENT_H
