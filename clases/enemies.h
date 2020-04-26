//
// Created by Agustin on 25/4/2020.
//

#ifndef RAYLIBTEMPLATE_ENEMIES_H
#define RAYLIBTEMPLATE_ENEMIES_H
#include <raylib.h>
#include <string>

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
    void Draw()

}
#endif //RAYLIBTEMPLATE_ENEMIES_H
