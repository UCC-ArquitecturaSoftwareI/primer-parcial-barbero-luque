//
// Created by Agustin on 25/4/2020.
//

#include "enemies.h"
#include <string>

void Enemy::setPatch(Texture2D e) {
    enemie = e;
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
    renderer.drawEnemy(this->enemie,this->getEnemie_pos().x, this->getEnemie_pos().y);
}

void Enemy::setEnemie_pos(Vector2 pos) {
    enemie_pos.x = pos.x;
    enemie_pos.y = pos.y;
}

Enemy::Enemy() {
    level = 0;
    speed = 0;
    hp = 100;
    damage = 20;
    enemie_pos.x = 0;
    enemie_pos.y = 0;
    toDie = false;
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
    enemy->setDamage(20);
    return *this;
}

EnemieBuilder &EasyEnemie::buildMovement() {
    if(enemy->getEnemie_pos().x==290 && enemy->getEnemie_pos().y<330){
        //if (rand() %2==0)
        enemy->move_y(1);
    }
    else if(enemy->getEnemie_pos().x==500){
        enemy->move_y(-1);
        if(enemy->getEnemie_pos().y<0){
            // activeEnemies.remove(*i);
            //p.pdamage(5);
        }
    }
    else{
        enemy->move_x(1);
    }
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
    enemy->setDamage(60);
    return *this;
}


EnemieBuilder &MediumEnemie::buildMovement() {
    if(enemy->getEnemie_pos().x==290 && enemy->getEnemie_pos().y<330){
        //if (rand() %2==0)
        enemy->move_y(1);
    }
    else if(enemy->getEnemie_pos().x==500){
        enemy->move_y(-1);
        if(enemy->getEnemie_pos().y<0){
            // activeEnemies.remove(*i);
            //p.pdamage(5);
        }
    }
    else{
        enemy->move_x(1);
    }
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
    enemy->setPatch( LoadTexture("resources/towerDefense_tile245.png") );
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
    enemy->setPatch( LoadTexture("resources/towerDefense_tile245.png") );
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
    enemy->setDamage(60);
    return *this;
}


EnemieBuilder &HardEnemie::buildMovement() {
    if(enemy->getEnemie_pos().x==290 && enemy->getEnemie_pos().y<330){
        //if (rand() %2==0)
        enemy->move_y(1);
    }
    else if(enemy->getEnemie_pos().x==500){
        enemy->move_y(-1);
        if(enemy->getEnemie_pos().y<0){
            //p.pdamage(5);
        }
    }
    else{
        enemy->move_x(1);
    }
    return *this;
}

EnemieBuilder &HardEnemie::buildTexture() {
    enemy->setPatch( LoadTexture("resources/towerDefense_tile245.png") );
    return *this;
}