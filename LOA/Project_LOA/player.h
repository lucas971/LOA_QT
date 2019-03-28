#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <QString>
class Player
{
public:
   int _id;
   static int _player_id;

   Player();
   Player(QString username, QString email);
   Player(QString username, QString email, double weight, double height, int age);
   Player(const Player & player);
   Player playerFromFile(QString file_name);
   ~Player();
   QString _username;
   QString _email;
   double _weight;
   double _height;
   int _age;


};


#endif // USER_HPP
