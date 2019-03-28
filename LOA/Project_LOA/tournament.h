#ifndef TOURNAMENT_H
#define TOURNAMENT_H
#include <string>
#include <tree.h>
#include <sport.h>
#include <team.h>
#include <QVector>
#include <QJsonDocument>

class Tournament
{
public:


   int _id;
   static int _tourn_id;
   QString _tournamentname;
   Sport _sport;
   QString _password;
   int _roundCount;
   int _maxSub;
   int _sub;
   QVector<Team> _teams;
   //Tree _tournamenttree;

   Tournament();
   Tournament(QString name, Sport sport, QString password, int roundCount, int maxSub, int sub, QVector<Team> teams);
   //, Tree tournamenttree);
   Tournament(const Tournament & tournament);
   ~Tournament();

   QJsonDocument loadJson(QString fileName);
   void saveJson(QJsonDocument document, QString fileName);
   void writefile3(Tournament t, QString fileName);
};

#endif // TOURNAMENT_H
