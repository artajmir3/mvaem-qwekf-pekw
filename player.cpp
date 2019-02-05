#include "player.h"

Player::Player(string username, string password)
{
    this->username = username;
    this->password = password;
    this->numLoose = 0;
    this->numWin = 0;
}

Player::Player()
{

}

void Player::win(){
    this->numWin++;
}

void Player::loose(){
    this->numLoose++;
}

int Player::getWin(){
    return this->numWin;
}

string Player::get_username(){
    return this->username;
}
