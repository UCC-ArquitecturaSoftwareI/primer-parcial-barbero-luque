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

    EnemieBuilder &target;

    float speed=0;
    Vector2 pos{};
    float damage;
    rendering<projectile> renderer;
    Texture2D projTexture{};
public:

    projectile(EnemieBuilder &t, float s, Vector2 p, Texture2D pT, float d): target(t)
    {
        target=t ;
        speed=s;
        pos=p;
        damage=d;
        projTexture=pT;
    }
    const EnemieBuilder &getTarget() const {
        return target;
    }

    void setTarget(const EnemieBuilder &target) {
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

    const Texture2D &getProjTexture() const;

    void setProjTexture(const Texture2D &projTexture);

    projectile();


};


/*projectile::projectile(): target(); {

}*/

#endif //RAYLIBTEMPLATE_PROJECTILE_H
