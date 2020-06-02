//
// Created by Francisco on 21/4/2020.
//

#ifndef PROYECTO_TORRE_H
#define PROYECTO_TORRE_H

#include <string>
#include "enemies.h"
#include "rendering.h"

class tower{
protected:
    int cost;
    std::string name;
    Vector2 tower_pos;
    Texture2D towerTexture;
public:
    tower(int a, std::string b, const Vector2 &towerPos, std::string patch);

    int getcost(){
        return cost;
    };

    std::string getname()
    {
        return name;
    };

    void fireProj(enemies);

    void setTowerPosition(Vector2);
};
#endif //PROYECTO_TORRE_H
