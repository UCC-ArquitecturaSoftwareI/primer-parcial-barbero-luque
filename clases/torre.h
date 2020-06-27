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
    tower();

    int cost;
    std::string name;
    Vector2 tower_pos;
    std::string towerTextureBase;
    std::string towerTextureTop;
    std::string towerType;
public:
    const std::string &getTowerType() const;

    void setTowerType(const std::string &towerType);

public:
    void setTowerTextureTop(const std::string &towerTextureTop);

public:
    void setCost(int cost);

protected:
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

    tower(const tower &t);

    int getcost(){
        return cost;
    };

    std::string getname()
    {
        return name;
    };
    int cooldownTick();
    virtual void fireProj(std::list<projectile> &activeProjectiles);

    void setTowerPosition(Vector2);

    void draw();

    Enemy* findInRange();

    bool operator==(tower t)
    {
        return tower_pos.x == t.tower_pos.x && tower_pos.y == t.tower_pos.y && towerType == t.towerType;
    }

    Vector2 GetTowerPos()
    {
        return tower_pos;
    }
};

class AreaTowerDecorator : public tower
{
private:
    tower &t;
public:
    AreaTowerDecorator(tower &t, tower &t1) : tower(t), t(t1) {
        t.setCost(300);
        t.setTowerTextureTop("resources/TowerTopArea.png");
        t.setTowerType("Area");
    }

    /*explicit AreaTowerDecorator(tower &t) : t(t) {

    }*/

    void fireProj(std::list<projectile> &activeProjectiles) override
    {
        t.fireProj(activeProjectiles);
        activeProjectiles.back().setImpactbehavior(new aoeTargetMissile);
    };

};

class StrongTowerDecorator : public tower
{
private:
    tower &t;
public:
    StrongTowerDecorator(tower &t, tower &t1) : tower(t), t(t1) {
        t.setCost(200);
        t.setTowerTextureTop("resources/TowerTopStrong.png");
        t.setTowerType("Strong");
    }

    /*explicit StrongTowerDecorator(tower &t) : t(t) {
        t.setCost(200);
        t.setTowerTextureTop("resources/TowerTopStrong.png");
    }*/

    void fireProj(std::list<projectile> &activeProjectiles) override
    {
        t.fireProj(activeProjectiles);
        activeProjectiles.back().setDamage(50);
    };


};
#endif //PROYECTO_TORRE_H
