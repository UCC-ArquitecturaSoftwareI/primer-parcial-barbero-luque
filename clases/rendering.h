//
// Created by Agustin on 29/4/2020.
//

#ifndef RAYLIBTEMPLATE_RENDERING_H
#define RAYLIBTEMPLATE_RENDERING_H

#include "raylib.h"

template <class T>
class rendering{
public:
    void drawEnemy(Texture2D a, float x, float y){
         DrawTexture(a, x - a.width/2, y- a.height/2, WHITE);
    }
    
};

#endif //RAYLIBTEMPLATE_RENDERING_H
