//
// Created by Agustin on 25/4/2020.
//

#include "enemies.h"
#include <string>
#include <utility>

void Enemy::setPatch(std::string e) {
    enemie = std::move(e);
}

void Enemy::move_x(float d) {
    enemie_pos.x += d*speed;
}

void Enemy::move_y(float d) {
    enemie_pos.y += d*speed;
}

Vector2 Enemy::getEnemie_pos() {
    return enemie_pos;
}

int Enemy::getLevel() const {
    return level;
}

float Enemy::getSpeed() const {
    return speed;
}

int Enemy::getHP() const {
    return hp;
}

int Enemy::getDamage() const {
    return damage;
}

void Enemy::setLevel(int l) {
    level = l;
}

void Enemy::setSpeed(float s) {
    speed = s;
}

void Enemy::setHP(int nhp) {
    hp = nhp;
}

void Enemy::setDamage(int ndmg) {
    damage = ndmg;
}

void Enemy::draw(){
    renderer.drawEnemy(this->enemie,this->getEnemie_pos().x, this->getEnemie_pos().y, rot);
}

void Enemy::setEnemie_pos(Vector2 pos) {
    enemie_pos.x = pos.x;
    enemie_pos.y = pos.y;
}

void Enemy::startMove() {
    if(this->getEnemie_pos().x==290 && this->getEnemie_pos().y<330){
        //if (rand() %2==0)
        this->move_y(1);
        rot=270;
    }
    else if(this->getEnemie_pos().x==500){
        this->move_y(-1);
        rot=90;
        if(this->getEnemie_pos().y<0){
            //p.pdamage(5);
        }
    }
    else{
        this->move_x(1);
        rot=0;
    }
}

Enemy::~Enemy() {

}


EnemieBuilder &EasyEnemie::buildLevel() {
    enemy->level = 1;
    return *this;
}

EnemieBuilder &EasyEnemie::buildSpeed() {
    enemy->setSpeed(0.75);
    return *this;
}

EnemieBuilder &EasyEnemie::buildHP() {
    enemy->setHP(75);
    return *this;
}

EnemieBuilder &EasyEnemie::buildDamage() {
    enemy->setDamage(5);
    return *this;
}

EnemieBuilder &MediumEnemie::buildLevel() {
    enemy->setLevel(2);
    return *this;
}

EnemieBuilder &MediumEnemie::buildSpeed() {
    enemy->setSpeed(1);
    return *this;
}

EnemieBuilder &MediumEnemie::buildHP() {

    enemy->setHP(100);
    return *this;
}

EnemieBuilder &MediumEnemie::buildDamage() {
    enemy->setDamage(10);
    return *this;
}




EnemieBuilder &EasyEnemie::buildInitialPosition() {
    Vector2 initialPos;
    initialPos.x = 20;
    initialPos.y = 85;
    enemy->setEnemie_pos(initialPos);
    return *this;
}

EnemieBuilder &EasyEnemie::buildTexture() {
    enemy->setPatch("resources/towerDefense_tile245.png");
    return *this;
}

EnemieBuilder &MediumEnemie::buildInitialPosition() {
    Vector2 initialPos;
    initialPos.x = 20;
    initialPos.y = 85;
    enemy->setEnemie_pos(initialPos);
    return *this;
}

EnemieBuilder &MediumEnemie::buildTexture() {
    enemy->setPatch("resources/towerDefense_tile245.png");
    return *this;
}

EnemieBuilder &HardEnemie::buildInitialPosition() {
    Vector2 initialPos;
    initialPos.x = 20;
    initialPos.y = 85;
    enemy->setEnemie_pos(initialPos);
    return *this;
}

EnemieBuilder &HardEnemie::buildLevel() {
    enemy->setLevel(3);
    return *this;
}

EnemieBuilder &HardEnemie::buildSpeed() {
    enemy->setSpeed(1.25);
    return *this;
}

EnemieBuilder &HardEnemie::buildHP() {
    enemy->setHP(125);
    return *this;
}

EnemieBuilder &HardEnemie::buildDamage() {
    enemy->setDamage(15);
    return *this;
}



EnemieBuilder &HardEnemie::buildTexture() {
    enemy->setPatch("resources/towerDefense_tile245.png");
    return *this;
}
