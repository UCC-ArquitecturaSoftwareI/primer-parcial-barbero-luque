//
// Created by Agustin on 25/4/2020.
//

#ifndef RAYLIBTEMPLATE_ENEMIES_H
#define RAYLIBTEMPLATE_ENEMIES_H

#include "rendering.h"
#include <raylib.h>
#include <string>

class Enemy {
protected:
    int level;
    float speed;
    int hp;
    int damage;
    Vector2 enemie_pos;
    Texture2D enemie;
    rendering<Enemy> renderer;
    bool toDie = false;
public:
    void setPatch(Texture2D);

    void move_x(float d);

    void move_y(float d);

    void draw();

    Vector2 getEnemie_pos();

    Texture2D getTexture() {
        return enemie;
    }

    int getLevel() const;

    float getSpeed() const;

    int getHP() const;

    int getDamage() const;

    void setLevel(int);

    void setSpeed(float);

    void setHP(int);

    void setDamage(int);

    void takeDamage(int d) {
        hp -= d;
        if (hp <= 0)
            toDie = true;
    }

    bool gettoDie() const {
        return toDie;
    }

    friend class EasyEnemie;
};

class EnemieBuilder {
protected:
    Enemy *enemy;
public:
    EnemieBuilder &newEnemy() {
        enemy = new Enemy;
    };

    virtual EnemieBuilder &buildLevel() = 0;

    virtual EnemieBuilder &buildSpeed() = 0;

    virtual EnemieBuilder &buildHP() = 0;

    virtual EnemieBuilder &buildDamage() = 0;

    virtual EnemieBuilder &buildInitialPosition() = 0;

    virtual EnemieBuilder &buildMovement() = 0;

    virtual EnemieBuilder &buildTexture() = 0;


    Enemy *get() {
        return enemy;
    }
};

class EasyEnemie : public EnemieBuilder {
public:
    EnemieBuilder &buildLevel() override;

    EnemieBuilder &buildSpeed() override;

    EnemieBuilder &buildHP() override;

    EnemieBuilder &buildDamage() override;

    EnemieBuilder &buildInitialPosition() override;

    EnemieBuilder &buildMovement() override;
};




class MediumEnemie : public EnemieBuilder {
public:
    EnemieBuilder &buildLevel() override;

    EnemieBuilder &buildSpeed() override;

    EnemieBuilder &buildHP() override;

    EnemieBuilder &buildDamage() override;

    EnemieBuilder &buildInitialPosition() override;

    EnemieBuilder &buildMovement() override;
};

class HardEnemie : public EnemieBuilder {
public:
    EnemieBuilder &buildLevel() override;

    EnemieBuilder &buildSpeed() override;

    EnemieBuilder &buildHP() override;

    EnemieBuilder &buildDamage() override;

    EnemieBuilder &buildInitialPosition() override;

    EnemieBuilder &buildMovement() override;

};

class Cuartel {
    EnemieBuilder &builder;
public:
    Cuartel(EnemieBuilder &builder) : builder(builder) {}

    void construct() {
        builder.newEnemy()
                .buildLevel()
                .buildHP()
                .buildDamage()
                .buildSpeed()
                .buildInitialPosition()
                .buildMovement().
                get();
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