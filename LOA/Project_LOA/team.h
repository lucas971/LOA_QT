#ifndef TEAM_H
#define TEAM_H
#include <string>
#include <player.h>
#include <vector>
#include <QVector>

class Team
{
public:
    int _id;
    static int _team_id;


public:
    int _count;
    QString _teamName;
    QString _website;
    QVector<Player> _members;

    Team();
    Team(int count, QString name, QString website);
    Team(const Team & team);
    ~Team();
};


#endif // TEAM_H
