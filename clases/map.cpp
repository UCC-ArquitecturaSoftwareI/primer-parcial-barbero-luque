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
    if(CheckCollisionRecs(a,{165 , 85 , 165 , 35}))
    {
        return true;
    }
    if(CheckCollisionRecs(a,{295 , 210 , 35 , 160}))
    {
        return true;
    }
    if(CheckCollisionRecs(a,{400 , 336 , 140 , 35}))
    {
        return true;
    }
    if(CheckCollisionRecs(a,{507 , 185 , 35 , 185}))
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

