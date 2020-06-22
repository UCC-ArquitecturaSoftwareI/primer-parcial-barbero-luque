//
// Created by Francisco on 1/6/2020.
//
#include "raylib.h"
#include "rendering.h"
#include "enemies.h"
#ifndef RAYLIBTEMPLATE_PROJECTILE_H
#define RAYLIBTEMPLATE_PROJECTILE_H

class projectile{

private:

    Enemy &target;

    float speed=0;
    Vector2 pos{};
    float damage;
    rendering<projectile> renderer;
    Texture2D *projTexture;
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

public:

    projectile(Enemy &t, float s, Vector2 p, Texture2D *pT, float d):target(t)
    {
        target=t ;
        speed=s;
        pos=p;
        damage=d;
        projTexture=pT;
        //fireframes=f;
    }
    const Enemy &getTarget() const {
        return target;
    }

    void setTarget(const Enemy &target) {
        projectile::target = target;
    }
    float getSpeed() const;

    void setSpeed(float speed);

    const Vector2 &getPos() const;

    void setPos(const Vector2 &pos);

    float getDamage() const;

    void setDamage(float damage);

    const rendering<projectile> &getRenderer() const;

    void setRenderer(const rendering<projectile> &renderer);
    void move();

    void draw();

    bool gettoDie()
    {
        return toDie;
    }
    projectile();

    ~projectile()
    {
        UnloadTexture(*projTexture);
    }

};


/*projectile::projectile(): target(); {

}*/

#endif //RAYLIBTEMPLATE_PROJECTILE_H
