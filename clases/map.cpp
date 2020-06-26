//
// Created by Agustin on 26/4/2020.
//

#include "map.h"

Texture2D mapTexture;
Rectangle mapRec;
void mapInit()
{
    mapRec = {0,0,static_cast<float>(GetScreenWidth()/15), static_cast<float>(GetScreenHeight())};
    mapTexture = LoadTexture("resources/Map1.png");

}
void mapDraw()
{
    DrawTexture(mapTexture, 0,0 ,WHITE);
}

void mapUnload()
{
    UnloadTexture(mapTexture);
}

bool checkCollision(Rectangle a, std::list<tower> &towers) {
    if(CheckCollisionRecs(a,{0 , 85 , 330 , 40}))
    {
        return true;
    }
    if(CheckCollisionRecs(a,{295 , 40 , 40 , 340}))
    {
        return true;
    }
    if(CheckCollisionRecs(a,{400 , 336 , 140 , 40}))
    {
        return true;
    }
    if(CheckCollisionRecs(a,{507 , 0 , 40 , 350}))
    {
        return true;
    }

    for(auto i=towers.begin();i!=towers.end();++i)
    {
        if(CheckCollisionRecs(a,{i->GetTowerPos().x,i->GetTowerPos().y,32,32}))
        {
            return true;
        }
    }

    return false;
}

