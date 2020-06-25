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

class projectile{

private:

    Enemy &target;

    float speed=0;
    Vector2 pos{};
    float damage;
    rendering renderer;
    std::string projTexture;
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

    projectile(Enemy &t, float s, Vector2 p, std::string *pT, float d, rendering r):target(t), renderer(r)
    {
        target=t ;
        speed=s;
        pos=p;
        damage=d;
        projTexture=*pT;
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

    const rendering &getRenderer() const;

    void setRenderer(const rendering &renderer);
    void move();

    void draw();

    bool gettoDie()
    {
        return toDie;
    }


};


/*projectile::projectile(): target(); {

}*/

#endif //RAYLIBTEMPLATE_PROJECTILE_H
