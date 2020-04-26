//
// Created by Agustin on 26/4/2020.
//

#include "map.h"

Texture2D mapTexture;
Rectangle mapRec;
void mapInit()
{
    mapRec = {0,0,static_cast<float>(GetScreenWidth()/15), static_cast<float>(GetScreenHeight())};
    mapTexture = LoadTexture("resources/mapTest.png");

}
void mapDraw()
{
    DrawTexture(mapTexture, 0,0 ,WHITE);
}

void mapUnload()
{
    UnloadTexture(mapTexture);
}