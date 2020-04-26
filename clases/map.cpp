//
// Created by Agustin on 26/4/2020.
//

#include "map.h"

Texture2D mapTexture;
Rectangle mapRec;
void mapInit()
{
    mapRec={static_cast<float>(GetScreenWidth()-(GetScreenWidth()/5)),0,static_cast<float>(GetScreenWidth()/5*2), static_cast<float>(GetScreenHeight())};
    mapTexture = LoadTexture("resources/mapTest.png");

}
void mapDraw()
{
    DrawTexture(mapTexture, static_cast<float>(GetScreenWidth()-(GetScreenWidth()/5)*1.54),0 ,WHITE);
}

void mapUnload()
{
    UnloadTexture(mapTexture);
}