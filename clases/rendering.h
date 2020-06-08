//
// Created by Agustin on 29/4/2020.
//

#ifndef RAYLIBTEMPLATE_RENDERING_H
#define RAYLIBTEMPLATE_RENDERING_H

#include <list>
#include "raylib.h"

template <class T>
class rendering{
private:
    int currentframe=0;
public:
    //TODO: PASAR TODO A DRAWTEXTUREEXTENDED
    void drawEnemy(Texture2D a, float x, float y){
         DrawTexture(a, x - a.width/2, y- a.height/2, WHITE);
    }

    void drawPhantomTextureTower(Texture2D base, Texture2D tope, float x, float y)
    {
        DrawTexture(base, x - base.width/2, y- base.height/2, GREEN);
        DrawTexture(tope, x - tope.width/2, y- tope.height/2, GREEN);
    }

    void drawTower(Texture2D base, Texture2D tope, float x, float y){
        DrawTexture(base, x - base.width/2, y- base.height/2, WHITE);
        DrawTexture(tope, x - tope.width/2, y- tope.height/2, WHITE);
    }

    /*void drawProjectile(Texture2D missile, std::list<Texture2D> &fireframes, float x, float y, float offset)
    {
        DrawTexture(missile,x,y,WHITE);
        int j=0;
        for(auto i=fireframes.begin(); i!=fireframes.end();++i)
        {
            if(j==currentframe)
            {
                DrawTexture(*i,x,y-offset,WHITE);
            }
            j++;
        }
        if(j<currentframe)
        {
            DrawTexture(*fireframes.begin(),x,y-offset,WHITE);
            currentframe=0;
        }
        currentframe++;
        } TODO: PULIR Y LOGRAR QUE ANDE.
    */

    void drawProjectile(Texture2D missile, float x, float y)
    {
        DrawTexture(missile,x,y,WHITE);
    }
};

#endif //RAYLIBTEMPLATE_RENDERING_H
