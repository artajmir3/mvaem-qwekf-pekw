#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player
{
private:
//    char username[20];
//    char password[20];
    string username;
    string password;
    int numLoose;
    int numWin;
public:
    Player(string username, string password);
    Player();
    string get_username();
    bool is_valid(string given_password);
    void loose();
    void win();
    int getWin();
};

#endif // PLAYER_H
