#ifndef SPORT_H
#define SPORT_H
#include <string>
#include <QString>

class Sport
{
public:

   int _id;
   static int _sport_id;

public:
   QString _sportname;
   Sport();
   Sport(QString sportname);
   ~Sport();
};

#endif // SPORT_H
