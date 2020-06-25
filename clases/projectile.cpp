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




void projectile::move() {
    if(target.gettoDie())
    {
        toDie=true;
        return;
    }
    Vector2 movVector = {target.getEnemie_pos().x - pos.x, target.getEnemie_pos().y - pos.y};

    //std::cout << pos.x << "   " << pos.y << std::endl;
    Normalize(movVector);
    pos.x += movVector.x * speed;
    pos.y += movVector.y * speed;
    if (CheckCollisionCircles(pos, 15, target.getEnemie_pos(), 15)) {
        target.takeDamage(15);
        toDie = true;
    }
}

void projectile::draw() {
    float angle=atan2_approximation1(target.getEnemie_pos().y-pos.y,target.getEnemie_pos().x-pos.x);
    renderer.drawProjectile(projTexture, pos.x, pos.y,angle);
}
