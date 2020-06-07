//
// Created by Francisco on 28/4/2020.
//

#ifndef RAYLIBTEMPLATE_PLAYER_H
#define RAYLIBTEMPLATE_PLAYER_H

class Player{
private:
    int playerhealth=100;
    int playermaxhealth=100;
    int playermoney=0;
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
