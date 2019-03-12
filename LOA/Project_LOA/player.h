#ifndef USER_HPP
#define USER_HPP
#include <string>

using namespace std;

class Player
{
   int _id;
   static int _player_id;
   string _username;
   string _email;
   float _weight;
   float _height;
   int _age;

public:
   Player();
   Player(std::string username, std::string email);
   Player(std::string username, std::string email, float weight, float height, int age);
   Player(const Player &);
   ~Player();

};


#endif // USER_HPP
