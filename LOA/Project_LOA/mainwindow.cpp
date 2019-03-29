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
    QModelIndex index = view->selectionModel()->currentIndex();
    QAbstractItemModel *model = view->model();

    Player *p = &_db->players.find(model->data(model->index(index.row(),2, index.parent())).toInt()).value();
    p->_username = userNameLineEdit->text();
    p->_age = ageSpinBox->value();
    p->_email = mailLineEdit->text();
    p->_height = heightDoubleSpinBox->value();
    p->_weight = weightDoubleSpinBox->value();
    model->setData(model->index(index.row(),0,index.parent()), p->_username, Qt::EditRole);
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
    model->setData(child, tr("Tournament"), Qt::EditRole);

    child = model->index(index.row()+1, 2, index.parent());
    model->setData(child, t->_id , Qt::EditRole);

    view->selectionModel()->setCurrentIndex(model->index(0, 0, index),
                                            QItemSelectionModel::ClearAndSelect);
    createChild(tr("Teams"), tr(""));

    view->selectionModel()->clear();
    updateActions();
}


void MainWindow::removeRow()
{
    QModelIndex index = view->selectionModel()->currentIndex();
    QAbstractItemModel *model = view->model();

    if (model->index(index.row(),1, index.parent()).data().toString() == "Team"){
        int key = model->index(index.row(),2, index.parent()).data().toInt();
        model->removeRow(index.row(), index.parent());
        _db->teams.remove(key);
    }
    else if (model->index(index.row(),1, index.parent()).data().toString() == "Tournament"){
        int key = model->index(index.row(),2, index.parent()).data().toInt();
        model->removeRow(index.row(), index.parent());
        _db->tournaments.remove(key);
    }

    view->selectionModel()->clear();
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
            removeRowAction->setEnabled(false);
            createNewTeam();
        }
        else if (model->index(index.row(),1, index.parent()).data().toString() == "Player"){
            removeRowAction->setEnabled(false);
            editPlayer(model->index(index.row(),2, index.parent()).data().toInt());
        }
        else if (model->index(index.row(),1, index.parent()).data().toString() == "Team"){
            removeRowAction->setEnabled(true);
            removeRowAction->setText(tr("Remove the team"));
            editTeam(model->index(index.row(),2, index.parent()).data().toInt());
        }
        else if (model->index(index.row(),1, index.parent()).data().toString() == "Tournament"){
            removeRowAction->setEnabled(true);
            removeRowAction->setText(tr("Remove the tournament"));
            editTournament(model->index(index.row(),2, index.parent()).data().toInt());
        }
        else{
            removeRowAction->setEnabled(false);
            showNothing();
        }
    }

    else{

        removeRowAction->setEnabled(false);
        createNewTournament();
    }
}

void MainWindow::chosePlayer(Player player){
    ageSpinBox->setValue(player._age);
    heightDoubleSpinBox->setValue(player._height);
    weightDoubleSpinBox->setValue(player._weight);
    userNameLineEdit->setText(player._username);
    mailLineEdit->setText(player._email);
    stackedWidget->setCurrentIndex(0);
}
void MainWindow::editPlayer(int id){
    Player p = _db->players.find(id).value();
    ageSpinBox->setValue(p._age);
    heightDoubleSpinBox->setValue(p._height);
    weightDoubleSpinBox->setValue(p._weight);
    userNameLineEdit->setText(p._username);
    mailLineEdit->setText(p._email);
    stackedWidget->setCurrentIndex(0);
}

void MainWindow::createNewTournament(){
    view->selectionModel()->clear();
    nameLineEdit->setText(tr(""));
    numberOfTeamsSpinBox->setValue(2);
    numberOfRoundsSpinBox->setValue(1);
    maxEntriesSpinBox->setValue(4);
    sportLineEdit->setText(tr(""));
    stackedWidget->setCurrentIndex(1);
}

void MainWindow::editTournament(int id){
    Tournament * t = &_db->tournaments.find(id).value();
    editNameLineEdit->setText(t->_tournamentname);
    stackedWidget->setCurrentIndex(7);
}

void MainWindow::createNewTeam(){
    teamNameLineEdit->setText(tr(""));
    websiteLineEdit->setText(tr(""));
    stackedWidget->setCurrentIndex(5);
}

void MainWindow::editTeam(int id){
    Team * t = &_db->teams.find(id).value();
    editTeamNameLineEdit->setText(t->_teamName);
    editTeamWebsiteLineEdit->setText(t->_website);
    stackedWidget->setCurrentIndex(4);
}

void MainWindow::showNothing(){
    stackedWidget->setCurrentIndex(6);
}
void MainWindow::on_pushButton_clicked() // Team Creation
{
    QModelIndex index = view->selectionModel()->currentIndex();
    QAbstractItemModel *model = view->model();

    Tournament * tou = &_db->tournaments.find(model->data(model->index(index.parent().row(),2)).toInt()).value();
    Team * t = new Team(tou->_teamsSize, teamNameLineEdit->text(), websiteLineEdit->text());
    tou->_teams->append(*t);
    _db->teams.insert(t->_id, *t);
    createChild(t->_teamName, tr("Team"), t->_id);
    view->selectionModel()->setCurrentIndex(index.child(0,0), QItemSelectionModel::ClearAndSelect);
    for (int i = 0; i < t->_count; i++){

        Player * p = new Player(tr("Unnamed player"), tr(""));
        _db->players.insert(p->_id,*p);
        t->_members->append(*p);
        createChild(p->_username, tr("Player"), p->_id);
    }
    updateActions();
}

void MainWindow::on_pushButton_2_clicked() // Team Edition
{
    QModelIndex index = view->selectionModel()->currentIndex();
    QAbstractItemModel *model = view->model();

    Team *t = &_db->teams.find(model->data(model->index(index.row(),2, index.parent())).toInt()).value();
    t->_teamName = editTeamNameLineEdit->text();
    t->_website = editTeamWebsiteLineEdit->text();
    model->setData(model->index(index.row(),0,index.parent()), t->_teamName, Qt::EditRole);
}

void MainWindow::on_pushButton_3_clicked()
{
    QModelIndex index = view->selectionModel()->currentIndex();
    QAbstractItemModel *model = view->model();
    Tournament *t = &_db->tournaments.find(model->data(model->index(index.row(),2, index.parent())).toInt()).value();
    t->_tournamentname = editNameLineEdit->text();
    model->setData(model->index(index.row(),0,index.parent()), t->_tournamentname, Qt::EditRole);
}

void MainWindow::on_actionCr_er_un_tournoi_triggered()
{
    createNewTournament();
}
