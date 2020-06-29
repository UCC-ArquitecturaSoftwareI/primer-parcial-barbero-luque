//
// Created by Agustin on 7/6/2020.
//
#include "projectile.h"

float projectile::getSpeed() const {
    return speed;
}

void projectile::setSpeed(float speed) {
    projectile::speed = speed;
}

const Vector2 &projectile::getPos() const {
    return pos;
}

void projectile::setPos(const Vector2 &pos) {
    projectile::pos = pos;
}

float projectile::getDamage() const {
    return damage;
}

void projectile::setDamage(float damage) {
    projectile::damage = damage;
}



/**
 *  Funcion clave del proyectil, si el objetivo esta por morir este tambien se autodestruye, sino se mueve
 *  en dirección a su objetivo, una vez lo suficientemente cerca, realiza su funcion strategy de impacto (si la tiene)
 *  o sino solo realiza daño. Posteriormente el misil se autodestruye.
 */
void projectile::move() {
    if(target->gettoDie())
    {
        toDie=true;
        return;
    }
    Vector2 movVector = {target->getEnemie_pos().x - pos.x, target->getEnemie_pos().y - pos.y};

    //std::cout << pos.x << "   " << pos.y << std::endl;
    Normalize(movVector);
    pos.x += movVector.x * speed;
    pos.y += movVector.y * speed;
    if (CheckCollisionCircles(pos, 15, target->getEnemie_pos(), 15)) {
        if(behavior)
            behavior->impact(target,eList, damage);
        else
            target->takeDamage(damage);
        toDie = true;
    }
}
/**
 *  Calcula la rotacion del misil a su objetivo y lo dibuja
 */
void projectile::draw() {
    float angle=fast_atan2(target->getEnemie_pos().y-pos.y,target->getEnemie_pos().x-pos.x);
    renderer.drawProjectile(projTexture, pos.x, pos.y,angle);
}

void projectile::setImpactbehavior(impactBehavior *b) {
    behavior=b;

}

//Strategies para dos tipos distintos de misiles.
void singleTargetMissile::impact(Enemy *target, std::list<Enemy*> &eList, int d) {
    target->takeDamage(d);
}
/**
 *  Realiza daño en area. Buscando en la lista enemigos cercanos que tambien le hacen daño
 */
void aoeTargetMissile::impact(Enemy *target, std::list<Enemy*> &eList, int d) {
    for(auto i=eList.begin();i!=eList.end();++i)
    {
        if(abs((*i)->getEnemie_pos().x-target->getEnemie_pos().x)<=100 && abs((*i)->getEnemie_pos().y-target->getEnemie_pos().y)<=100 && !(*i)->gettoDie())
        {
            (*i)->takeDamage(d);
        }
    }
    //std::cout<<"AREA DAMAGE"<<std::endl;
}
