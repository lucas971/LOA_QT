#include "player.h"
#include <string>

using namespace std;

int Player::_player_id=0;

Player::Player(){
    _id=_player_id++;
    _username="";
    _email="";
    _weight=65;
    _height= 1.80f;
    _age=25;
    return;
}

Player::Player(std::string username, std::string email){
    _id=_player_id+1;
    _username=username;
    _email=email;
    return;
}

Player::Player(std::string username, std::string email, float weight, float height, int age){
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

