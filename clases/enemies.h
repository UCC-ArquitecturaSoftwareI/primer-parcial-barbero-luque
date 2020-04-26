//
// Created by Agustin on 25/4/2020.
//

#include <raylib.h>
#include <string>

#ifndef RAYLIBTEMPLATE_ENEMIES_H
#define RAYLIBTEMPLATE_ENEMIES_H

class enemies {
private:
    int level;
    float speed;
    int hp;
    Vector2 enemie_pos;
    Texture2D enemie;
public:
    enemies(int level, const Vector2 &enemiePos, std::string patch);
    void move_x(float d);
    void move_y(float d);
    void draw();
}
#endif //RAYLIBTEMPLATE_ENEMIES_H
