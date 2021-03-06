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
    virtual void hookadditionalFireProperties(std::list<projectile> &activeProjectiles) const=0;
    int cost;
    std::string name;
    Vector2 tower_pos;
    std::string towerTextureBase;
    std::string towerTextureTop;
    std::string projectileText;
    int currentCooldown=0;
    int maxCooldown=60;
    rendering &renderer=rendering::get();
    int damage;

    std::list<Enemy*> &eList;

    Enemy* CurrentTarget;

    static inline float fast_atan2(float y, float x){
        static const float c1 = M_PI / 4.0;
        static const float c2 = M_PI * 3.0 / 4.0;
        if (y == 0 && x == 0)
            return 0;
        float abs_y = fabsf(y);
        float angle;
        if (x >= 0)
            angle = c1 - c1 * ((x - abs_y) / (x + abs_y));
        else
            angle = c2 - c1 * ((x + abs_y) / (abs_y - x));
        if (y < 0)
            return -angle;
        return angle;
    }


public:

    tower(int a, std::string b, const Vector2 &towerPos, std::string patch, std::string patch2, std::list<Enemy*> &enL);

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

    Enemy* findInRange();

    Vector2 GetTowerPos()
    {
        return tower_pos;
    }
};
//TemplateMethods para mayores funcionalidades.

class NormalTower:public tower
{
public:
    NormalTower(int a, std::string b, const Vector2 &towerPos, std::string patch, std::string patch2, std::list<Enemy*> &enL):
            tower(a, b, towerPos, patch,  patch2, enL){};

    /**
 *  Clase Base, la funcion a llenar se deja vacia.
 */
    void hookadditionalFireProperties(std::list<projectile> &activeProjectiles) const override {
        //std::cout<<"HERE"<<std::endl;
    }

};


class AreaTower: public NormalTower
{
public:
    AreaTower(int a, std::string b, const Vector2 &towerPos, std::string patch, std::string patch2, std::list<Enemy*> &enL):
            NormalTower(a, b,  towerPos, patch,  patch2, enL){};
    /**
 *  Aplica un strategy al misil despues de crearlo en fireProj
 */
    void hookadditionalFireProperties(std::list<projectile> &activeProjectiles) const override
    {
            //std::cout<<"ADDED AREA DAMAGE"<<std::endl;
            activeProjectiles.back().setImpactbehavior(new aoeTargetMissile);
    }

};

class StrongTower:public NormalTower
{
public:
    StrongTower(int a, std::string b, const Vector2 &towerPos, std::string patch, std::string patch2, std::list<Enemy*> &enL):
            NormalTower(a, b, towerPos, patch,  patch2, enL){};
    /**
 *  Aumenta el Daño del misil despues de crearlo en FireProj
 */
    void hookadditionalFireProperties(std::list<projectile> &activeProjectiles) const override {
            //std::cout<<"ADDED EXTRA DAMAGE"<<std::endl;
            activeProjectiles.back().setDamage(70);
        }

};


#endif //PROYECTO_TORRE_H
