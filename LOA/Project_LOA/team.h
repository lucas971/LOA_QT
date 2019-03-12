#ifndef TEAM_H
#define TEAM_H
#include <string>
#include <player.h>
#include <vector>


class Team
{
    int _id;
    static int _team_id;
    int _count;
    std::string _teamName;
    std::string _website;
    std::vector<Player> _members;


public:
    Team();
    Team(int count, std::string name, std::string website, std::vector<Player> members);
    Team(const Team & team);
    ~Team();
};


#endif // TEAM_H
