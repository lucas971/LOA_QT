#include "mainwindow.h"
#include "tournament.h"
#include "player.h"
#include "branch.h"
#include "sport.h"
#include "team.h"
#include "tree.h"
#include <QApplication>
#include <QSplitter>
#include <QFileSystemModel>
#include <QTreeView>
#include <QListView>
#include <QFile>
#include <QTextStream>
#include <QVector>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(editabletreemodel);

    QApplication app(argc, argv);
    MainWindow window;
    window.show();

    Tournament* t;
    Team* team1;
    Team* team2;
    Team* team3;
    Team* team4;
    Tree* tournament_tree;
    Sport* sport1;

    sport1 = new Sport("footbal_en_solo", true, 2);

    Player* p1;
    Player* p2;
    Player* p3;
    Player* p4;

    p1 = new Player("joueur1", "", 1.8f, 2.0f, 22);
    p2 = new Player("joueur2", "", 1.8f, 2.0f, 22);
    p3 = new Player("joueur3", "", 1.8f, 2.0f, 22);
    p4 = new Player("joueur4", "", 1.8f, 2.0f, 22);


    QVector<Player> members; // = new QVector<Player>;
    QVector<Player> members2; //= new QVector<Player>;
    QVector<Player> members3; //= new QVector<Player>;
    QVector<Player> members4; // = new QVector<Player>;

    members.push_back(*p1);
    members2.push_back(*p2);
    members3.push_back(*p3);
    members4.push_back(*p4);

    QVector<Team> teams;

    team1 = new Team(1, "la_team_1", "website", members);
    team2 = new Team(1, "la_team_2", "website", members2);
    team3 = new Team(1, "la_team_3", "website", members3);
    team4 = new Team(1, "la_team_4", "website", members4);

    teams.push_back(*team1);
    teams.push_back(*team2);
    teams.push_back(*team3);
    teams.push_back(*team4);

    Branch* branch1;
    Branch* branch2;
    Branch* branch3;

    branch1 = new Branch(*team1, *team2, true, 1, 3, 0);
    branch2 = new Branch(*team3, *team4, true, 4, 0, 2);
    branch3 = new Branch(*team1, *team4, false, 0, 0, 0);

    QVector<Branch> branch;
    branch.push_back(*branch1);
    branch.push_back(*branch2);
    branch.push_back(*branch3);

    //tournament_tree = Tree(2, 3, branch);
    t = new Tournament("tounoi 1", *sport1, "1234", 3, 10, 4, teams);
    //, tournament_tree);

    t->writefile3(*t, "out.json");
    return app.exec();
}
