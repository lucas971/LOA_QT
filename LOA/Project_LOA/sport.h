#ifndef SPORT_H
#define SPORT_H
#include <string>

class Sport
{
   int _id;
   static int _sport_id;
   std::string _sportname;
   bool _team;
   int _teamCount;

public:
   Sport();
   Sport(std::string sportname, bool team, int teamCount);
   Sport(const Sport & sport);
   ~Sport();

};

#endif // SPORT_H
