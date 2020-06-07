//
// Created by Agustin on 1/6/2020.
//
#include "player.h"

int Player::getPlayerHealth(){
    return playerhealth;
}

int Player::getPlayerMaxHealth() {
    return playermaxhealth;
}

void Player::startplayer(){
    playerhealth=playermaxhealth;
}

void Player::pdamage(int d){
    playerhealth -=d;
    if (playerhealth<0){
        playerhealth=0;
    }
}

void Player::pheal(int h){
    playerhealth+=h;
    if(playerhealth>playermaxhealth)
        playerhealth=playermaxhealth;
}

bool Player::isPlayerdead(){
    return playerhealth==0;
}

void Player::setPlayerHealth(int newPH) {
    playerhealth = newPH;
}

void Player::setPlayerMaxHealth(int newPMH) {
    playermaxhealth = newPMH;
}

int Player::getPlayerMoney() {
    return playermoney;
}

void Player::setPlayerMoney(int m) {
    playermoney = m;
}

int Player::takeMoney(int m) {
    if(playermoney>m){
        playermoney-=m;
        return 1;
    }
    return 0;
}

void Player::giveMoney(int m) {
    playermoney+=m;
}
