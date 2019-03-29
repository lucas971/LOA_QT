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
   QString _password;

public:
   QString _tournamentname;
   QString _sport;
   int _maxSub;
   int _roundCount;
   int _sub;
   Tree* _tournamenttree;
   QVector<Team>* _teams;
   Tournament();
   Tournament(QString name, QString sport, QString password, int roundCount, int maxSub);
   Tournament(const Tournament & tournament);
   ~Tournament();
   QJsonDocument loadJson(QString fileName);
   void saveJson(QJsonDocument document, QString fileName);
   void writefile3(Tournament t, QString fileName);
};

#endif // TOURNAMENT_H
