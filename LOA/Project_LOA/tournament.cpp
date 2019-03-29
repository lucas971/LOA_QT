#include "tournament.h"
#include "sport.h"
#include "team.h"
#include <vector>
#include <string>

#include<QFile>
#include<QTextStream>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

int Tournament::_tourn_id=0;

Tournament::Tournament(){
    _id=_tourn_id++;
    _tournamentname = "_";
    _sport = "_";
    _password = "";
    _roundCount = 1;
    _maxSub = 2;
    _sub = 2;
    //_tournamenttree = Tree();
}


Tournament::Tournament(QString name, QString sport, QString password, int roundCount, int maxSub){
    _id=_tourn_id++;
    _tournamentname = name;
    _sport = sport;
    _password = password;
    _roundCount = roundCount;
    _maxSub = maxSub;
    _sub = 0;
    _tournamenttree = new Tree(maxSub);
    _teams = new QVector<Team>(maxSub);
    return;
}

Tournament::Tournament(const Tournament & tournament){
    _id=_tourn_id++;
    _tournamentname = tournament._tournamentname;
    _sport = tournament._sport;
    _password = tournament._password;
    _roundCount = tournament._roundCount;
    _maxSub = tournament._maxSub;
    _sub = tournament._sub;
    _teams = tournament._teams;
    _tournamenttree = tournament._tournamenttree;
}

Tournament::~Tournament(){
    delete this;
}
QJsonDocument loadJson(QString fileName) {
    QFile jsonFile(fileName);
    jsonFile.open(QFile::ReadOnly);
    return QJsonDocument().fromJson(jsonFile.readAll());
}

void saveJson(QJsonDocument document, QString fileName) {
    QFile jsonFile(fileName);
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(document.toJson());
}

void Tournament::writefile3(Tournament t, QString fileName){

    QJsonObject tournamentObject;
    tournamentObject.insert("Tournament name", QJsonValue::fromVariant(t._tournamentname));

    QJsonObject sportObject;
    sportObject.insert("Sport name", QJsonValue::fromVariant((t._sport)));

    tournamentObject.insert("Sport", sportObject);

    tournamentObject.insert("Password", QJsonValue::fromVariant(t._password));
    tournamentObject.insert("Round Count", QJsonValue::fromVariant(t._roundCount));
    tournamentObject.insert("Max Subscribers", QJsonValue::fromVariant(t._maxSub));
    tournamentObject.insert("Nb Subscribers", QJsonValue::fromVariant(t._sub));


    QJsonObject teamsObject;
    QJsonObject teamObject;

    for (int i=0; i<t._teams->size(); i++){
        teamObject.insert("Team Name",QJsonValue::fromVariant(t._teams->at(i)._teamName));
        teamObject.insert("Count",QJsonValue::fromVariant(t._teams->at(i)._count));
        teamObject.insert("Website",QJsonValue::fromVariant(t._teams->at(i)._website));

        QString team_i = "Team" + QString::number(i);

        QJsonArray playersArray;
        QJsonObject playerObject;
        for (int j=0; j<t._teams->at(i)._count; j++){
            playerObject.insert("User Name", QJsonValue::fromVariant(t._teams->at(i)._members->at(j)._username));
            playerObject.insert("Email", QJsonValue::fromVariant(t._teams->at(i)._members->at(j)._email));
            playerObject.insert("Weight", QJsonValue::fromVariant(t._teams->at(i)._members->at(j)._weight));
            playerObject.insert("Height", QJsonValue::fromVariant(t._teams->at(i)._members->at(j)._height));
            playerObject.insert("Age", QJsonValue::fromVariant(t._teams->at(i)._members->at(j)._age));

            QString player_j = "Player" + QString::number(j);
            playersArray.push_back(playerObject);
        }
        teamObject.insert("Players", playersArray);

        teamsObject.insert(team_i, teamObject);
    }
    tournamentObject.insert("Teams", teamsObject);


    QJsonObject treeObject;
    treeObject.insert("Height", QJsonValue::fromVariant(t._tournamenttree._height));
    treeObject.insert("Width", QJsonValue::fromVariant(t._tournamenttree._width));

    QJsonObject branchsObject;
    QJsonObject branchObject;
    QJsonObject team1Object;
    QJsonObject team2Object;
    for(int l=0; l<t._tournamenttree._branches->size(); l++){

        team1Object.insert("Count", QJsonValue::fromVariant(t._tournamenttree._branches->at(l)._team1._count));
        team1Object.insert("Team Name", QJsonValue::fromVariant(t._tournamenttree._branches->at(l)._team1._teamName));
        team1Object.insert("Website", QJsonValue::fromVariant(t._tournamenttree._branches->at(l)._team1._website));

        QJsonArray playersArray;
        QJsonObject playerObject;
        for (int j=0; j<t._tournamenttree._branches->at(l)._team1._count; j++){
            playerObject.insert("User Name", QJsonValue::fromVariant(t._tournamenttree._branches->at(l)._team1._members.at(j)._username));
            playerObject.insert("Email", QJsonValue::fromVariant(t._tournamenttree._branches->at(l)._team1._members.at(j)._email));
            playerObject.insert("Weight", QJsonValue::fromVariant(t._tournamenttree._branches->at(l)._team1._members.at(j)._weight));
            playerObject.insert("Height", QJsonValue::fromVariant(t._tournamenttree._branches->at(l)._team1._members.at(j)._height));
            playerObject.insert("Age", QJsonValue::fromVariant(t._tournamenttree._branches->at(l)._team1._members.at(j)._age));

            playersArray.push_back(playerObject);
        }
        team1Object.insert("Players", playersArray);
        branchObject.insert("Team1", team1Object);

        team2Object.insert("Count", QJsonValue::fromVariant(t._tournamenttree._branches->at(l)._team2._count));
        team2Object.insert("Team Name", QJsonValue::fromVariant(t._tournamenttree._branches->at(l)._team2._teamName));
        team2Object.insert("Website", QJsonValue::fromVariant(t._tournamenttree._branches->at(l)._team2._website));

        for (int j=0; j<t._tournamenttree._branches->at(l)._team2._count; j++){
            playerObject.insert("User Name", QJsonValue::fromVariant(t._tournamenttree._branches->at(l)._team2._members.at(j)._username));
            playerObject.insert("Email", QJsonValue::fromVariant(t._tournamenttree._branches->at(l)._team2._members.at(j)._email));
            playerObject.insert("Weight", QJsonValue::fromVariant(t._tournamenttree._branches->at(l)._team2._members.at(j)._weight));
            playerObject.insert("Height", QJsonValue::fromVariant(t._tournamenttree._branches->at(l)._team2._members.at(j)._height));
            playerObject.insert("Age", QJsonValue::fromVariant(t._tournamenttree._branches->at(l)._team2._members.at(j)._age));

            playersArray.push_back(playerObject);
        }
        team2Object.insert("Players", playersArray);
        branchObject.insert("Team2", team2Object);

        QString branch_l = "Branch_" + QString::number(l);

        branchsObject.insert(branch_l, branchObject);
    }
    treeObject.insert("Tree", branchsObject);
    tournamentObject.insert("Branches", treeObject);

    QJsonArray recordsArray;
    recordsArray.push_back(tournamentObject);
    QJsonDocument doc(recordsArray);

    //On écrit dans un fichier du nom fileName
    QFile jsonFile(fileName);
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(doc.toJson());

}
/*
    QJsonObject recordObject;
    recordObject.insert("FirstName", QJsonValue::fromVariant("John"));
    recordObject.insert("LastName", QJsonValue::fromVariant("Doe"));
    recordObject.insert("Age", QJsonValue::fromVariant(43));

    QJsonObject addressObject;
    addressObject.insert("Street", "Downing Street 10");
    addressObject.insert("City", "London");
    addressObject.insert("Country", "Great Britain");
    recordObject.insert("Address", addressObject);

    QJsonArray phoneNumbersArray;
    phoneNumbersArray.push_back("+44 1234567");
    phoneNumbersArray.push_back("+44 2345678");
    recordObject.insert("Phone Numbers", phoneNumbersArray);

    QJsonArray recordsArray;
    recordsArray.push_back(recordObject);
    QJsonDocument doc(recordsArray);

*/

