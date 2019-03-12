#include "mainwindow.h"
#include <QApplication>
#include <QSplitter>
#include <QFileSystemModel>
#include <QTreeView>
#include <QListView>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(editabletreemodel);

    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}
