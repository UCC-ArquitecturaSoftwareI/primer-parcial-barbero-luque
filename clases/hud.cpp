//
// Created by Francisco on 24/4/2020.
//
#include "hud.h"

Texture2D hudTexturePanel;
Rectangle hudRightPanel;

Texture2D healthbarBaseText;


Texture2D healthbarOverText;


void hudInit()
{
    hudRightPanel={static_cast<float>(GetScreenWidth()-(GetScreenWidth()/5)),0,static_cast<float>(GetScreenWidth()/5*2), static_cast<float>(GetScreenHeight())};
    hudTexturePanel = LoadTexture("resources/HudPanelRight.png");

    healthbarBaseText=LoadTexture("resources/health_bar_decoration.png");
    healthbarOverText=LoadTexture("resources/health_bar.png");
}
void hudDraw()
{
    DrawTexture(hudTexturePanel, static_cast<float>(GetScreenWidth()-(GetScreenWidth()/5)*1.54),0 ,WHITE);
    DrawTexture(healthbarBaseText, 5 , static_cast<float>(GetScreenHeight()) - 20 , WHITE);

    DrawTexture(healthbarOverText, 19 , static_cast<float>(GetScreenHeight()) - 20 , WHITE);

}

void hudUnload()
{
    UnloadTexture(hudTexturePanel);
}