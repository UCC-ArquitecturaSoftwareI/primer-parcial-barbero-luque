//
// Created by Agustin on 25/4/2020.
//

#include "enemies.h"
#include <string>


int EnemieBuilder::getLevel() const {
    return level;
}

float EnemieBuilder::getSpeed() const {
    return speed;
}

int EnemieBuilder::getHP() const {
    return hp;
}

void EnemieBuilder::setLevel(int l) {
    level = l;
}

void EnemieBuilder::setSpeed(float s) {
    speed = s;
}

void EnemieBuilder::setHP(int nhp) {
    hp = nhp;
}

int EnemieBuilder::getDamage() const {
    return damage;
}

void EnemieBuilder::setDamage(int d) {
    damage = d;
}

void EnemieBuilder::move_x(float d) {
    enemie_pos.x += d*speed;
}

void EnemieBuilder::move_y(float d) {
    enemie_pos.y += d*speed;
}

Vector2 EnemieBuilder::getEnemie_pos() {
    return enemie_pos;
}

void EnemieBuilder::setPatch(Texture2D e) {
    enemie = e;
}

EnemieBuilder &EasyEnemie::buildLevel() {
    level = 1;
    return *this;
}

EnemieBuilder &EasyEnemie::buildSpeed() {
    speed = 0.75;
    return *this;
}

EnemieBuilder &EasyEnemie::buildHP() {
    hp = 75;
    return *this;
}

EnemieBuilder &EasyEnemie::buildDamage() {
    damage = 20;
    return *this;
}

EnemieBuilder &EasyEnemie::buildDraw() {
    renderer.drawEnemy(this->enemie, this->getEnemie_pos().x, this->getEnemie_pos().y);
    return *this;
}

EnemieBuilder &EasyEnemie::buildMovement() {
    if(this->getEnemie_pos().x==290 && this->getEnemie_pos().y<330){
        //if (rand() %2==0)
        this->move_y(1);
    }
    else if(this->getEnemie_pos().x==500){
        this->move_y(-1);
        if(this->getEnemie_pos().y<0){
            // activeEnemies.remove(*i);
            //p.pdamage(5);
        }
    }
    else{
        this->move_x(1);
    }
    return *this;
}


EnemieBuilder &MediumEnemie::buildLevel() {
    level = 2;
    return *this;
}

EnemieBuilder &MediumEnemie::buildSpeed() {
    speed = 1;
    return *this;
}

EnemieBuilder &MediumEnemie::buildHP() {

    hp = 100;
    return *this;
}

EnemieBuilder &MediumEnemie::buildDamage() {
    damage = 40;
    return *this;
}

EnemieBuilder &MediumEnemie::buildDraw() {
    renderer.drawEnemy(this->enemie,this->getEnemie_pos().x, this->getEnemie_pos().y);
    return *this;
}

EnemieBuilder &MediumEnemie::buildMovement() {
    if(this->getEnemie_pos().x==290 && this->getEnemie_pos().y<330){
        //if (rand() %2==0)
        this->move_y(1);
    }
    else if(this->getEnemie_pos().x==500){
        this->move_y(-1);
        if(this->getEnemie_pos().y<0){
            // activeEnemies.remove(*i);
            //p.pdamage(5);
        }
    }
    else{
        this->move_x(1);
    }
    return *this;
}

EnemieBuilder &EasyEnemie::buildInitialPosition() {
    this->enemie_pos.x = 20;
    this->enemie_pos.y = 85;
    return *this;
}

EnemieBuilder &EasyEnemie::buildTexture() {
    setPatch( LoadTexture("resources/towerDefense_tile245.png") );
    return *this;
}

EnemieBuilder &MediumEnemie::buildInitialPosition() {
    this->enemie_pos.x = 20;
    this->enemie_pos.y = 85;
    return *this;
}

EnemieBuilder &MediumEnemie::buildTexture() {
    setPatch( LoadTexture("resources/towerDefense_tile245.png") );
    return *this;
}

EnemieBuilder &HardEnemie::buildInitialPosition() {
    this->enemie_pos.x = 20;
    this->enemie_pos.y = 85;
    return *this;
}

EnemieBuilder &HardEnemie::buildLevel() {
    level = 3;
    return *this;
}

EnemieBuilder &HardEnemie::buildSpeed() {
    speed = 1.25;
    return *this;
}

EnemieBuilder &HardEnemie::buildHP() {
    hp = 125;
    return *this;
}

EnemieBuilder &HardEnemie::buildDamage() {
    damage = 60;
    return *this;
}

EnemieBuilder &HardEnemie::buildDraw() {
    renderer.drawEnemy(this->enemie,this->getEnemie_pos().x, this->getEnemie_pos().y);
    return *this;
}

EnemieBuilder &HardEnemie::buildTexture() {
    setPatch( LoadTexture("resources/towerDefense_tile245.png") );
    return *this;
}

EnemieBuilder &HardEnemie::buildMovement() {
    if(this->getEnemie_pos().x==290 && this->getEnemie_pos().y<330){
        //if (rand() %2==0)
        this->move_y(1);
    }
    else if(this->getEnemie_pos().x==500){
        this->move_y(-1);
        if(this->getEnemie_pos().y<0){
            //p.pdamage(5);
        }
    }
    else{
        this->move_x(1);
    }
    return *this;
}
