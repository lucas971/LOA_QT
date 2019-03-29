#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "player.h"
#include <QMainWindow>
#include <QModelIndex>

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

public slots:
    void updateActions();

private slots:
    void createChild(QString name, QString type, QMap<int, QVariant> map);
    void insertChild();
    void removeRow();
    void setInsertChildName(QString typeToInsert);

    void chosePlayer(Player player);
    void createNewPlayer();

    void createNewTournament();
    void on_Valider_2_clicked();
    void on_Valider_clicked();
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
