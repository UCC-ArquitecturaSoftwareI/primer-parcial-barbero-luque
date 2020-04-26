//
// Created by Agustin on 25/4/2020.
//

#include "enemies.h"

Texture2D enemiesTexture;

enemies::enemies(int lvl, const Vector2 &enemiePos, std::string patch) : enemie_pos(enemiePos) {
    level = lvl;
    if( lvl == 1 ){
        speed = 0.5;
        hp = 75;
    }else if ( lvl == 2 ){
        speed = 0.75;
        hp = 100;
    }else{
        speed = 1;
        hp = 125;
    }
    enemie = LoadTexture(patch.c_str());
}

void enemies::draw() {
    DrawTexture(enemie, enemie_pos.x - enemie.width/2, enemie_pos.y- enemie.height/2, WHITE);
}

void enemies::move_x(float d) {
    enemie_pos.x += d; // ACTUALIZAR CON SPEED
}
void enemies::move_y(float d) {
    enemie_pos.y += d; // ACTUALIZAR CON SPEED
}


