//
// Created by Francisco on 21/4/2020.
//

#ifndef PROYECTO_TORRE_H
#define PROYECTO_TORRE_H

#include <string>
#include "enemies.h"
#include "rendering.h"
#include "projectile.h"
#include "math.h"

class tower{
protected:
    int cost;
    std::string name;
    Vector2 tower_pos;
    std::string towerTextureBase;
    std::string towerTextureTop;
    std::string projectileText;
    int currentCooldown=0;
    int maxCooldown=60;
    rendering renderer;

    std::list<Enemy> &eList;

    Enemy &CurrentTarget;

    float atan2_approximation1(float y, float x) //Aproximacion rapida de tangente conseguido de github.
    {

        const float ONEQTR_PI = M_PI / 4.0;
        const float THRQTR_PI = 3.0 * M_PI / 4.0;
        float r, angle;
        float abs_y = fabs(y) + 1e-10f;
        if ( x < 0.0f )
        {
            r = (x + abs_y) / (abs_y - x);
            angle = THRQTR_PI;
        }
        else
        {
            r = (x - abs_y) / (x + abs_y);
            angle = ONEQTR_PI;
        }
        angle += (0.1963f * r * r - 0.9817f) * r;
        if ( y < 0.0f )
            return( -angle );
        else
            return( angle );


    }

public:
    tower(int a, std::string b, const Vector2 &towerPos, std::string patch, std::string patch2, std::list<Enemy> &enL, rendering &R);

    int getcost(){
        return cost;
    };

    std::string getname()
    {
        return name;
    };
    int cooldownTick();
    void fireProj(std::list<projectile> &activeProjectiles);

    void setTowerPosition(Vector2);

    void draw();

    Enemy & findInRange();

    Vector2 GetTowerPos()
    {
        return tower_pos;
    }
};
#endif //PROYECTO_TORRE_H
