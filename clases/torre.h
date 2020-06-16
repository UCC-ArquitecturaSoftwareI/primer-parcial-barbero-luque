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
    Texture2D projectileText;
    int currentCooldown=0;
    int maxCooldown=60;
    rendering<tower> renderer;

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
    void fireProj(EnemieBuilder &e, std::list<projectile> &activeProjectiles);

    void setTowerPosition(Vector2);

    void draw();
};
#endif //PROYECTO_TORRE_H
