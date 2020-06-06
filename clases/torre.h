//
// Created by Francisco on 21/4/2020.
//

#ifndef PROYECTO_TORRE_H
#define PROYECTO_TORRE_H

#include <string>
#include "enemies.h"
#include "rendering.h"
#include "projectile.h"

class tower{
protected:
    int cost;
    std::string name;
    Vector2 tower_pos;
    Texture2D towerTextureBase;
    Texture2D towerTextureTop;
    int currentCooldown=0;
    int maxCooldown=60;
public:
    tower(int a, std::string b, const Vector2 &towerPos, std::string patch, std::string patch2);

    int getcost(){
        return cost;
    };

    std::string getname()
    {
        return name;
    };
    int cooldownTick();
    projectile fireProj(EnemieBuilder &e);

    void setTowerPosition(Vector2);
};
#endif //PROYECTO_TORRE_H
