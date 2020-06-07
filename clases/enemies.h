//
// Created by Agustin on 25/4/2020.
//

#ifndef RAYLIBTEMPLATE_ENEMIES_H
#define RAYLIBTEMPLATE_ENEMIES_H

#include "rendering.h"
#include <raylib.h>
#include <string>


class EnemieBuilder{
protected:
    int level;
    float speed;
    int hp;
    int damage;
    Vector2 enemie_pos;
    Texture2D enemie;
    rendering<EnemieBuilder> renderer;
public:
    virtual EnemieBuilder& buildLevel() = 0;
    virtual EnemieBuilder& buildSpeed() = 0;
    virtual EnemieBuilder& buildHP() = 0;
    virtual EnemieBuilder& buildDamage() = 0;
    virtual EnemieBuilder& buildMovement() = 0;
    virtual EnemieBuilder& buildDraw() = 0;

    void move_x(float d);
    void move_y(float d);
    Vector2 getEnemie_pos();
    int getLevel() const;
    float getSpeed() const;
    int getHP() const;
    int getDamage() const;
    void setLevel(int);
    void setSpeed(float);
    void setHP(int);
    void setDamage (int);
};

class EasyEnemie : public EnemieBuilder {
public:
    EnemieBuilder &buildLevel() override;
    EnemieBuilder &buildSpeed() override;
    EnemieBuilder &buildHP() override;
    EnemieBuilder &buildDamage() override;
    EnemieBuilder &buildMovement() override;
    EnemieBuilder &buildDraw() override;
};

class MediumEnemie : public EnemieBuilder {
public:
    EnemieBuilder &buildLevel() override;
    EnemieBuilder &buildSpeed() override;
    EnemieBuilder &buildHP() override;
    EnemieBuilder &buildDamage() override;
    EnemieBuilder &buildMovement() override;
    EnemieBuilder &buildDraw() override;
};

class HardEnemie : public EnemieBuilder {
public:
    EnemieBuilder &buildLevel() override;
    EnemieBuilder &buildSpeed() override;
    EnemieBuilder &buildHP() override;
    EnemieBuilder &buildDamage() override;
    EnemieBuilder &buildMovement() override;
    EnemieBuilder &buildDraw() override;
};

class Cuartel{
    EnemieBuilder &builder;
public:
    Cuartel(EnemieBuilder &builder ) : builder(builder) {}

    void construct(){
        builder.buildLevel()
        .buildHP()
        .buildDamage()
        .buildSpeed()
        .buildDraw()
        .buildMovement();
    }
};

#endif //RAYLIBTEMPLATE_ENEMIES_H

/* IMPLEMENTACION
 *  EasyEnemie builderEasy;
 *  Cuartel cuartel( builderEasy );
 *  cuartel.construct();
 *
 *  cout << builderEasy.get();
 *
 */