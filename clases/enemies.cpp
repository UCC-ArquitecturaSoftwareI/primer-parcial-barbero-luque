//
// Created by Agustin on 25/4/2020.
//

#include "enemies.h"
#include <string>
#include <utility>

/**
 *  Aplica por medio de un string, la textura del enemigo
 *  Se le pasa un string como path de la textura
 */
void Enemy::setPatch(std::string e) {
    enemie = std::move(e);
}

/**
 *  Función dedicada a mover el enemigo por la posicion x
 *  Se le debe pasar como argumento la cantidad de posiciones en x que se desplazará
 */
void Enemy::move_x(float d) {
    enemie_pos.x += d*speed;
}

/**
 *  Función dedicada a mover el enemigo por la posicion y
 *  Se le debe pasar como argumento la cantidad de posiciones en y que se desplazará
 */
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

/**
 *  Dibuja el Enemy llamando al renderer
 */
void Enemy::draw(){
    renderer.drawEnemy(this->enemie,this->getEnemie_pos().x, this->getEnemie_pos().y, rot);
}

void Enemy::setEnemie_pos(Vector2 pos) {
    enemie_pos.x = pos.x;
    enemie_pos.y = pos.y;
}


/**
 *  A partir de los getters y setters de posiciones, con ésta funcion, el Enemy comienza a dar su recorrido
 *  por el mapa.
 */
void Enemy::startMove() {
    if(this->getEnemie_pos().x==290 && this->getEnemie_pos().y<330){
        //if (rand() %2==0)
        this->move_y(1);
        rot=90;
    }
    else if(this->getEnemie_pos().x==500){
        this->move_y(-1);
        rot=270;
    }
    else{
        this->move_x(1);
        rot=0;
    }
}

Enemy::~Enemy() {
}

/**
 *  A partir de nuestro Builder, para un enemigo llamado EasyEnemie, se le aplica el nivel 1.
 */
EnemieBuilder &EasyEnemie::buildLevel() {
    enemy->level = 1;
    return *this;
}

/**
 *  A partir de nuestro Builder, para un enemigo llamado EasyEnemie, se le aplica su velocidad.
 */
EnemieBuilder &EasyEnemie::buildSpeed() {
    enemy->setSpeed(0.75);
    return *this;
}

/**
 *  A partir de nuestro Builder, para un enemigo llamado EasyEnemie, se le aplica la vida.
 */
EnemieBuilder &EasyEnemie::buildHP() {
    enemy->setHP(75);
    return *this;
}

/**
 *  A partir de nuestro Builder, para un enemigo llamado EasyEnemie, se le aplica el daño.
 */
EnemieBuilder &EasyEnemie::buildDamage() {
    enemy->setDamage(5);
    return *this;
}

/**
 *  A partir de nuestro Builder, para un enemigo llamado MediumEnemie, se le aplica el nivel 2.
 */
EnemieBuilder &MediumEnemie::buildLevel() {
    enemy->setLevel(2);
    return *this;
}

/**
 *  A partir de nuestro Builder, para un enemigo llamado MediumEnemie, se le aplica la velocidad.
 */
EnemieBuilder &MediumEnemie::buildSpeed() {
    enemy->setSpeed(1);
    return *this;
}

/**
 *  A partir de nuestro Builder, para un enemigo llamado MediumEnemie, se le aplica la vida.
 */
EnemieBuilder &MediumEnemie::buildHP() {

    enemy->setHP(100);
    return *this;
}

/**
 *  A partir de nuestro Builder, para un enemigo llamado MediumEnemie, se le aplica el daño.
 */
EnemieBuilder &MediumEnemie::buildDamage() {
    enemy->setDamage(10);
    return *this;
}

/**
 *  A partir de nuestro Builder, para un enemigo llamado EasyEnemie, se le aplica la posicion inicial
 *  donde éste va a comenzar a dibujarse.
 */
EnemieBuilder &EasyEnemie::buildInitialPosition() {
    Vector2 initialPos;
    initialPos.x = 20;
    initialPos.y = 85;
    enemy->setEnemie_pos(initialPos);
    return *this;
}

/**
 *  A partir de nuestro Builder, para un enemigo llamado EasyEnemie, se le aplica por medio
 *  de la funcion setPatch la textura al enemy.
 */
EnemieBuilder &EasyEnemie::buildTexture() {
    enemy->setPatch("resources/towerDefense_tile245.png");
    return *this;
}

/**
 *  A partir de nuestro Builder, para un enemigo llamado MediumEnemie, se le aplica la posicion inicial
 *  donde éste va a comenzar a dibujarse.
 */
EnemieBuilder &MediumEnemie::buildInitialPosition() {
    Vector2 initialPos;
    initialPos.x = 20;
    initialPos.y = 85;
    enemy->setEnemie_pos(initialPos);
    return *this;
}

/**
 *  A partir de nuestro Builder, para un enemigo llamado MediumEnemie, se le aplica por medio
 *  de la funcion setPatch la textura al enemy.
 */
EnemieBuilder &MediumEnemie::buildTexture() {
    enemy->setPatch("resources/towerDefense_tile245.png");
    return *this;
}

/**
 *  A partir de nuestro Builder, para un enemigo llamado HardEnemie, se le aplica la posicion inicial
 *  donde éste va a comenzar a dibujarse.
 */
EnemieBuilder &HardEnemie::buildInitialPosition() {
    Vector2 initialPos;
    initialPos.x = 20;
    initialPos.y = 85;
    enemy->setEnemie_pos(initialPos);
    return *this;
}

/**
 *  A partir de nuestro Builder, para un enemigo llamado HardEnemie, se le aplica el nivel 3.
 */
EnemieBuilder &HardEnemie::buildLevel() {
    enemy->setLevel(3);
    return *this;
}

/**
 *  A partir de nuestro Builder, para un enemigo llamado HardEnemie, se le aplica la velocidad.
 */
EnemieBuilder &HardEnemie::buildSpeed() {
    enemy->setSpeed(1.25);
    return *this;
}

/**
 *  A partir de nuestro Builder, para un enemigo llamado HardEnemie, se le aplica la vida.
 */
EnemieBuilder &HardEnemie::buildHP() {
    enemy->setHP(125);
    return *this;
}

/**
 *  A partir de nuestro Builder, para un enemigo llamado HardEnemie, se le aplica el daño.
 */
EnemieBuilder &HardEnemie::buildDamage() {
    enemy->setDamage(15);
    return *this;
}


/**
 *  A partir de nuestro Builder, para un enemigo llamado MediumEnemie, se le aplica por medio
 *  de la funcion setPatch la textura al enemy.
 */
EnemieBuilder &HardEnemie::buildTexture() {
    enemy->setPatch("resources/towerDefense_tile245.png");
    return *this;
}
