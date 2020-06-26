//
// Created by Francisco on 1/6/2020.
//
#include <utility>

#include "raylib.h"
#include "rendering.h"
#include "enemies.h"
#include "math.h"
#ifndef RAYLIBTEMPLATE_PROJECTILE_H
#define RAYLIBTEMPLATE_PROJECTILE_H
class impactBehavior;

class projectile{

private:

    Enemy *target;

    float speed=0;
    Vector2 pos{};
    int damage;
    rendering &renderer=rendering::get();
    std::string projTexture;
    impactBehavior* behavior=nullptr;
    std::list<Enemy*> &eList;
    //std::list<Texture2D> fireframes{};
    bool toDie=false;



    inline float FastSqrtInvAroundOne(float x)
    {
        const float a0 = 15.0f / 8.0f;
        const float a1 = -5.0f / 4.0f;
        const float a2 = 3.0f / 8.0f;

        return a0 + a1 * x + a2 * x * x;
    }

    const Vector2 Normalize(const Vector2 &v)
    {
        const float len_sq = v.x * v.x + v.y * v.y;
        const float len_inv = FastSqrtInvAroundOne(len_sq);
        return Vector2{v.x * len_inv, v.y * len_inv};
    }

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

    projectile(Enemy *t, float s, Vector2 p, std::string *pT, int d, std::list<Enemy*> &eL):target(t), eList(eL)
    {
        target=t ;
        speed=s;
        pos=p;
        damage=d;
        projTexture=*pT;
        //fireframes=f;
    }
    const Enemy *getTarget() const {
        return target;
    }

    void setTarget(Enemy* target) {
        projectile::target = target;
    }
    float getSpeed() const;

    void setSpeed(float speed);

    const Vector2 &getPos() const;

    void setImpactbehavior(impactBehavior* b);

    void setPos(const Vector2 &pos);

    float getDamage() const;

    void setDamage(float damage);

    void move();

    void draw();



    bool gettoDie()
    {
        return toDie;
    }


};


/*projectile::projectile(): target(); {

}*/
class impactBehavior{
public:
    virtual void impact(Enemy *target, std::list<Enemy*> &eList, int d)=0;
};

class singleTargetMissile : public impactBehavior{
public:
    virtual void impact(Enemy *target, std::list<Enemy*> &eList, int d);
};
class aoeTargetMissile : public impactBehavior{
public:
    virtual void impact(Enemy *target, std::list<Enemy*> &eList, int d);
};


#endif //RAYLIBTEMPLATE_PROJECTILE_H
