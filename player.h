#ifndef PLAYER_H
#define PLAYER_H


class Player
{
private:
//    char username[20];
//    char password[20];
public:
    Player(char* username, char* password);
    Player();
    char* get_username();
    bool is_valid(char* given_password);
};

#endif // PLAYER_H
