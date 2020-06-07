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

const rendering<projectile> &projectile::getRenderer() const {
    return renderer;
}

void projectile::setRenderer(const rendering<projectile> &renderer) {
    projectile::renderer = renderer;
}

const Texture2D &projectile::getProjTexture() const {
    return projTexture;
}

void projectile::setProjTexture(const Texture2D &projTexture) {
    projectile::projTexture = projTexture;
}