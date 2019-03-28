#ifndef SPORT_H
#define SPORT_H
#include <QString>

class Sport
{
public:

   int _id;
   static int _sport_id;
   QString _sportname;
   bool _team;
   int _teamCount;

   Sport();
   Sport(QString sportname, bool team, int teamCount);
   Sport(const Sport & sport);
   ~Sport();

};

#endif // SPORT_H
