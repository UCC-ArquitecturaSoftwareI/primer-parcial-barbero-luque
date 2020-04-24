//
// Created by Francisco on 24/4/2020.
//
#include "hud.h"

Texture2D hudTexturePanel;
Rectangle hudRightPanel;
void hudInit()
{
    hudRightPanel={static_cast<float>(GetScreenWidth()-(GetScreenWidth()/5)),0,static_cast<float>(GetScreenWidth()/5*2), static_cast<float>(GetScreenHeight())};
    hudTexturePanel = LoadTexture("resources/HudPanelRight.png");

}
void hudDraw()
{
    DrawTexture(hudTexturePanel, static_cast<float>(GetScreenWidth()-(GetScreenWidth()/5)*1.54),0 ,WHITE);
}

void hudUnload()
{
    UnloadTexture(hudTexturePanel);
}