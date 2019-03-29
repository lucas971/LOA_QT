#include "mainwindow.h"
#include "treemodel.h"
#include "tournament.h"
#include "sport.h"
#include "database.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);

    QStringList headers;
    headers << tr("Nom") << tr("Type") << tr("Id");

    QFile file(":/default.txt");
    file.open(QIODevice::ReadOnly);
    TreeModel *model = new TreeModel(headers, tr(""));
    file.close();

    view->setModel(model);
    for (int column = 0; column < model->columnCount(); ++column)
        view->resizeColumnToContents(column);

    connect(exitAction, &QAction::triggered, qApp, &QCoreApplication::quit);

    connect(view->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &MainWindow::updateActions);

    connect(actionsMenu, &QMenu::aboutToShow, this, &MainWindow::updateActions);
    connect(removeRowAction, &QAction::triggered, this, &MainWindow::removeRow);
    connect(insertChildAction, &QAction::triggered, this, &MainWindow::insertChild);

    updateActions();
    _db = new Database();
}

void MainWindow::insertChild()
{
}

void MainWindow::on_Valider_clicked() //CREATION DE JOUEUR
{

}

void MainWindow::createChild(QString name, QString type, int id = -1, QMap<int, QVariant> map = QMap<int, QVariant>()){
    QModelIndex index = view->selectionModel()->currentIndex();
    QAbstractItemModel *model = view->model();

    if (model->columnCount(index) == 0) {
        if (!model->insertColumn(0, index))
            return;
    }

    if (!model->insertRow(0, index))
        return;
/*
    for (int column = 0; column < model->columnCount(index); ++column) {
        QModelIndex child = model->index(0, column, index);
        model->setData(child, QVariant("[No data]"), Qt::EditRole);
        if (!model->headerData(column, Qt::Horizontal).isValid())
            model->setHeaderData(column, Qt::Horizontal, QVariant("[No header]"), Qt::EditRole);
    }*/
    QModelIndex child = model->index(0, 0, index);
    model->setData(child, name, Qt::EditRole);
    child = model->index(0, 1, index);
    model->setData(child, type, Qt::EditRole);
    if (id!=-1){
        child = model->index(0, 2, index);
        model->setData(child, id, Qt::EditRole);
    }

    if (!map.isEmpty()){
        model->setItemData(index,map);
    }
    updateActions();

}


void MainWindow::on_Valider_2_clicked() //CREATION DE TOURNOI
{
    Tournament* t = new Tournament(nameLineEdit->text(), sportLineEdit->text(), nameLineEdit->text(), numberOfRoundsSpinBox->value(), numberOfTeamsSpinBox->value() ,maxEntriesSpinBox->value());

    _db->tournaments.insert(t->_id, *t);
    QModelIndex index = view->selectionModel()->currentIndex();
    QAbstractItemModel *model = view->model();

    if (!model->insertRow(index.row()+1, index.parent()))
        return;

    updateActions();

    QModelIndex child = model->index(index.row()+1, 0, index.parent());
    model->setData(child, QVariant(t->_tournamentname), Qt::EditRole);

    child = model->index(index.row()+1, 1, index.parent());
    model->setData(child, tr("Tournament of ").append(t->_sport), Qt::EditRole);

    child = model->index(index.row()+1, 2, index.parent());
    model->setData(child, t->_id, Qt::EditRole);

    view->selectionModel()->setCurrentIndex(model->index(0, 0, index),
                                            QItemSelectionModel::ClearAndSelect);

    createChild(QString::number((t->_maxSub)), tr("Max Team"));
    createChild(QString::number((t->_sub)), tr("Current Team Numbers"));
    createChild(tr("Teams"), tr(""));
    updateActions();
}


void MainWindow::removeRow()
{
    QModelIndex index = view->selectionModel()->currentIndex();
    QAbstractItemModel *model = view->model();
    if (model->removeRow(index.row(), index.parent()))
        updateActions();
}

void MainWindow::updateActions()
{
    bool hasSelection = !view->selectionModel()->selection().isEmpty();
    removeRowAction->setEnabled(hasSelection);

    bool hasCurrent = view->selectionModel()->currentIndex().isValid();

    if (hasCurrent) {
        view->closePersistentEditor(view->selectionModel()->currentIndex());

        int row = view->selectionModel()->currentIndex().row();
        int column = view->selectionModel()->currentIndex().column();

        if (view->selectionModel()->currentIndex().parent().isValid())
            statusBar()->showMessage(tr("Position: (%1,%2)").arg(row).arg(column));
        else
            statusBar()->showMessage(tr("Position: (%1,%2) in top level").arg(row).arg(column));

        QModelIndex index = view->selectionModel()->currentIndex();
        QAbstractItemModel *model = view->model();

        if (model->data((index)).toString() == "Teams"){
            createNewTeam();
        }
        qDebug() << model->index(index.row(),1, index.parent()).data();
        if (model->index(index.row(),1, index.parent()).data().toString() == "Player"){
            createNewPlayer();
        }
        else{
            insertChildAction->setText(tr(""));
            showNothing();
        }
    }

    else{
        insertChildAction->setText(tr("Insert a new tournament"));
        createNewTournament();

    }
}

void MainWindow::setInsertChildName(QString typeToInsert){
    insertChildAction->setText(tr("Insert a ").append(typeToInsert));
}

void MainWindow::chosePlayer(Player player){
    ageSpinBox->setValue(player._age);
    heightDoubleSpinBox->setValue(player._height);
    weightDoubleSpinBox->setValue(player._weight);
    userNameLineEdit->setText(player._username);
    mailLineEdit->setText(player._email);
    stackedWidget->setCurrentIndex(0);
}
void MainWindow::createNewPlayer(){
    ageSpinBox->setValue(0);
    heightDoubleSpinBox->setValue(0);
    weightDoubleSpinBox->setValue(0);
    userNameLineEdit->setText(tr(""));
    mailLineEdit->setText(tr(""));
    stackedWidget->setCurrentIndex(0);
}

void MainWindow::createNewTournament(){
    nameLineEdit->setText(tr(""));
    numberOfTeamsSpinBox->setValue(2);
    numberOfRoundsSpinBox->setValue(1);
    maxEntriesSpinBox->setValue(4);
    sportLineEdit->setText(tr(""));


    stackedWidget->setCurrentIndex(1);

}

void MainWindow::createNewTeam(){
    teamNameLineEdit->setText(tr(""));
    websiteLineEdit->setText(tr(""));
    stackedWidget->setCurrentIndex(4);
}

void MainWindow::showNothing(){
    stackedWidget->setCurrentIndex(6);
}
void MainWindow::on_pushButton_clicked()
{
    QModelIndex index = view->selectionModel()->currentIndex();
    QAbstractItemModel *model = view->model();
    Team * t = new Team(_db->tournaments.find(model->data(model->index(index.parent().row(),2)).toInt()).value()._teamsSize, teamNameLineEdit->text(), websiteLineEdit->text());
    _db->teams.insert(t->_id, *t);
    createChild(t->_teamName, tr("Team"), t->_id);
    view->selectionModel()->setCurrentIndex(index.child(0,0), QItemSelectionModel::ClearAndSelect);
    for (int i = 0; i < t->_count; i++){

        Player * p = new Player(tr("Unnamed player"), tr(""));
        _db->players.insert(p->_id,*p);
        createChild(p->_username, tr("Player"), p->_id);
    }
    updateActions();
}
