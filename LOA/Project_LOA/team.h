#ifndef TEAM_H
#define TEAM_H
#include <string>
#include <player.h>
#include <vector>

using namespace std;

class Team
{
    int _id;
    static int _team_id;
    int _count;
    string _teamName;
    string _website;
    std::vector<Player> _members;


public:
    Team();
    Team(int count, string name, string website, std::vector<Player> members);
    Team(const Team &);
    ~Team();
};


#endif // TEAM_H
