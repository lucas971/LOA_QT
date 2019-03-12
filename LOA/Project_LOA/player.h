#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Player
{
   int _id;
   static int _player_id;
   std::string _username;
   std::string _email;
   float _weight;
   float _height;
   int _age;

public:
   Player();
   Player(std::string username, std::string email);
   Player(std::string username, std::string email, float weight, float height, int age);
   Player(const Player & player);
   ~Player();

};


#endif // USER_HPP
