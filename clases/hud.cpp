//
// Created by Francisco on 24/4/2020.
//
#include <raylib.h>
Texture2D hudTexturePanel;
Rectangle hudRightPanel;

void hudInit()
{
    hudRightPanel={static_cast<float>(GetScreenWidth()-(GetScreenWidth()/5)),static_cast<float>(GetScreenHeight()/2),static_cast<float>(GetScreenWidth()/5), static_cast<float>(GetScreenHeight())};
    hudTexturePanel = LoadTexture("resources/HudPanelRight.jpg");

}
void hudDraw()
{
    DrawTextureRec(hudTexturePanel, hudRightPanel, Vector2{ static_cast<float>(GetScreenWidth()-(GetScreenWidth()/5)),static_cast<float>(GetScreenHeight()/2) } ,WHITE);
}

void hudUnload()
{
    UnloadTexture(hudTexturePanel);
}