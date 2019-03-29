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


    return app.exec();
}
