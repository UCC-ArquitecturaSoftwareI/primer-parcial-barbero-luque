//
// Created by Agustin on 25/4/2020.
//

#include "rendering.h"
#include <raylib.h>
#include <string>

#ifndef RAYLIBTEMPLATE_ENEMIES_H
#define RAYLIBTEMPLATE_ENEMIES_H

class enemies {
protected:
    int level;
    float speed;
    int hp;
    Vector2 enemie_pos;
    Texture2D enemie;
    rendering<enemies> renderer;

public:
    enemies(int lvl, const Vector2 &enemiePos, std::string patch);
    void move_x(float d);
    void move_y(float d);
    void draw();
    Vector2 getenemie_pos(){
        return enemie_pos;
    }
    float getSpeed() const;

    void setSpeed(float speed);
    Vector2 getEnemie_pos()
    {
        return enemie_pos;
    }

    Texture2D getenemie(){
        return enemie;
    }

};

#endif //RAYLIBTEMPLATE_ENEMIES_H
