#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "player.h"
#include "database.h"
#include <QMainWindow>
#include <QModelIndex>

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    Database* _db;

public slots:
    void updateActions();

private slots:
    void createChild(QString name, QString type, int id, QMap<int, QVariant> map);
    void insertChild();
    void removeRow();
    void setInsertChildName(QString typeToInsert);
    void showNothing();
    void chosePlayer(Player player);
    void editPlayer(int id);
    void createNewTeam();
    void editTeam(int id);

    void createNewTournament();
    void editTournament(int id);
    void on_Valider_2_clicked();
    void on_Valider_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
};

#endif // MAINWINDOW_H
