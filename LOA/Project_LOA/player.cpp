#include "player.h"
#include <string>
#include <QFile>
#include <QString>

int Player::_player_id=0;

Player::Player(){
    _id=_player_id++;
    _username="Unnamed player";
    _email="No email";
    _weight=0;
    _height=0;
    _age=18;
    return;
}

Player::Player(QString username, QString email){
    _id=_player_id+1;
    _username=username;
    _email=email;
    return;
}

Player::Player(QString username, QString email, double weight, double height, int age){
    _id=_player_id++;
    _username=username;
    _email=email;
    _weight=weight;
    _height=height;
    _age=age;
    return;
}

Player::Player(const Player & player){
    _id=_player_id++;
    _username=player._username;
    _email=player._email;
    _weight=player._weight;
    _height=player._height;
    _age=player._age;
}

Player::~Player(){

}

Player Player::playerFromFile(QString file_name){
    QFile file(file_name);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return Player();

    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        //process_line(line);
    }
}

