#ifndef TOURNAMENTTREEMODEL_H
#define TOURNAMENTTREEMODEL_H
#include <QStandardItemModel>
#include <player.h>

class TournamentTreeModel : QStandardItemModel {

    public :
    TournamentTreeModel();
    TournamentTreeModel(const TournamentTreeModel &);
    ~TournamentTreeModel();
    void AddPlayer(Player player);

};

#endif // PLAYERTREEMODEL_H
