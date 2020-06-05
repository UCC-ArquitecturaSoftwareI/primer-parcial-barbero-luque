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
public:
    virtual EnemieBuilder& buildLevel() = 0;
    virtual EnemieBuilder& buildSpeed() = 0;
    virtual EnemieBuilder& buildHP() = 0;
    virtual EnemieBuilder& buildDamage() = 0;

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
};

class MediumEnemie : public EnemieBuilder {
public:
    EnemieBuilder &buildLevel() override;

    EnemieBuilder &buildSpeed() override;

    EnemieBuilder &buildHP() override;

    EnemieBuilder &buildDamage() override;
};

class HardEnemie : public EnemieBuilder {
public:
    EnemieBuilder &buildLevel() override;

    EnemieBuilder &buildSpeed() override;

    EnemieBuilder &buildHP() override;

    EnemieBuilder &buildDamage() override;
};

class ReyEnemigo{
    EnemieBuilder &builder;
public:
    ReyEnemigo( EnemieBuilder &builder ) : builder(builder) {}

    void construct(){
        builder.buildLevel()
        .buildHP()
        .buildDamage()
        .buildSpeed();
    }
};

#endif //RAYLIBTEMPLATE_ENEMIES_H

/* IMPLEMENTACION
 *  EasyEnemie builderEasy;
 *  ReyEnemigo cuartel( builderEasy );
 *  cuartel.construct();
 *
 *  cout << builderEasy.get();
 *
 */