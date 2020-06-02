//
// Created by Francisco on 28/4/2020.
//

#ifndef RAYLIBTEMPLATE_PLAYER_H
#define RAYLIBTEMPLATE_PLAYER_H
int playerhealth;
int playermaxhealth=100;

class Player{
private:
    int playerhealth;
    int playermaxhealth;
    int playermoney;
public:

    void startplayer();
    void pdamage(int d);
    void pheal(int h);
    bool isPlayerdead();
    int takeMoney(int);
    void giveMoney(int);

    int getPlayerMoney();
    int getPlayerHealth();
    int getPlayerMaxHealth();

    void setPlayerHealth(int);
    void setPlayerMaxHealth(int);
    void setPlayerMoney(int);
};

#endif //RAYLIBTEMPLATE_PLAYER_H
