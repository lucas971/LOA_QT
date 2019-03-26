#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <QString>
class Player
{
   int _id;
   static int _player_id;

public:
   Player();
   Player(QString username, QString email);
   Player(QString username, QString email, double weight, double height, int age);
   Player(const Player & player);
   ~Player();
   QString _username;
   QString _email;
   double _weight;
   double _height;
   int _age;


};


#endif // USER_HPP
