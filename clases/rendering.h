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

    void drawPhantomTextureTower(Texture2D base, Texture2D tope, float x, float y)
    {
        DrawTexture(base, x - base.width/2, y- base.height/2, GREEN);
        DrawTexture(tope, x - tope.width/2, y- tope.height/2, GREEN);
    }

    
};

#endif //RAYLIBTEMPLATE_RENDERING_H
