//
// Created by Agustin on 25/4/2020.
//

#ifndef RAYLIBTEMPLATE_ENEMIES_H
#define RAYLIBTEMPLATE_ENEMIES_H

#include "rendering.h"
#include <raylib.h>
#include <string>
#include <utility>

class Enemy {
protected:
    int level;
    float speed;
    int hp;
    int damage;
    float rot=0;

    Vector2 enemie_pos{};
    std::string enemie;
    rendering &renderer=rendering::get();

    bool toDie = false;
public:
    /*Enemy(rendering r):renderer(r) {
        level = 0;
        speed = 0;
        hp = 100;
        damage = 20;
        enemie_pos.x = 0;
        enemie_pos.y = 0;
        toDie = false;
    }*/
    Enemy(){
        level = 0;
        speed = 0;
        hp = 100;
        damage = 5;
        enemie_pos.x = 0;
        enemie_pos.y = 0;
        toDie = false;
    }
    void setPatch(std::string);

    void move_x(float d);

    void move_y(float d);

    void startMove();

    void draw();

    Vector2 getEnemie_pos();
    void setEnemie_pos(Vector2);

    std::string getTexture() {
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
        //std::cout<<"CURRENTHP:"<<hp<<std::endl;
        if (hp <= 0)
            toDie = true;
    }

    bool gettoDie() const {
        return toDie;
    }

    void setToDie()
    {
        toDie=true;
    }

    int getLevel()
    {
        return level;
    }
    ~Enemy();
    friend class EasyEnemie;
};

class EnemieBuilder {
protected:
    Enemy *enemy;
public:
    /*EnemieBuilder &newEnemy(rendering r) {
        enemy = new Enemy(r);
        return *this;
    };
     */
    EnemieBuilder &newEnemy() {
        enemy = new Enemy();
        return *this;
    };

    virtual EnemieBuilder &buildLevel() = 0;

    virtual EnemieBuilder &buildSpeed() = 0;

    virtual EnemieBuilder &buildHP() = 0;

    virtual EnemieBuilder &buildDamage() = 0;

    virtual EnemieBuilder &buildInitialPosition() = 0;

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

    EnemieBuilder &buildTexture() override;
};




class MediumEnemie : public EnemieBuilder {
public:
    EnemieBuilder &buildLevel() override;

    EnemieBuilder &buildSpeed() override;

    EnemieBuilder &buildHP() override;

    EnemieBuilder &buildDamage() override;

    EnemieBuilder &buildInitialPosition() override;

    EnemieBuilder &buildTexture() override;
};

class HardEnemie : public EnemieBuilder {
public:
    EnemieBuilder &buildLevel() override;

    EnemieBuilder &buildSpeed() override;

    EnemieBuilder &buildHP() override;

    EnemieBuilder &buildDamage() override;

    EnemieBuilder &buildInitialPosition() override;

    EnemieBuilder &buildTexture() override;

};

class Cuartel {
    EnemieBuilder &builder;
public:
    Cuartel(EnemieBuilder &builder) : builder(builder) {}

    Enemy* construct() {
        return builder.newEnemy()
                .buildLevel()
                .buildHP()
                .buildDamage()
                .buildSpeed()
                .buildInitialPosition()
                .buildTexture().
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
