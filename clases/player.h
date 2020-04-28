//
// Created by Francisco on 28/4/2020.
//

#ifndef RAYLIBTEMPLATE_PLAYER_H
#define RAYLIBTEMPLATE_PLAYER_H
int playerhealth;
int playermaxhealth=100;

void startplayer(){
    playerhealth=playermaxhealth;
}

void pdamage(int d)
{
    playerhealth -=d;
    if (playerhealth<0)
    {
        playerhealth=0;
    }
}

void pheal(int h)
{
    playerhealth+=h;
    if(playerhealth>playermaxhealth)
        playerhealth=playermaxhealth;
}

int isPlayerdead()
{
    return playerhealth==0;
}
#endif //RAYLIBTEMPLATE_PLAYER_H
