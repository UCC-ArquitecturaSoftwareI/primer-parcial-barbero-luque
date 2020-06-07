//
// Created by Francisco on 24/4/2020.
//
#include "hud.h"

Texture2D hudTexturePanel;
Rectangle hudRightPanel;

Texture2D healthbarBaseText;

Texture2D towerCreateButton;

Texture2D healthbarOverText;


void hudInit()
{
    hudRightPanel={static_cast<float>(GetScreenWidth()-(GetScreenWidth()/5)),0,static_cast<float>(GetScreenWidth()/5*2), static_cast<float>(GetScreenHeight())};
    hudTexturePanel = LoadTexture("resources/HudPanelRight.png");

    healthbarBaseText=LoadTexture("resources/health_bar_decoration.png");
    healthbarOverText=LoadTexture("resources/health_bar.png");

    towerCreateButton=LoadTexture("resources/TowerCreateButton.png");
}

void hudDraw(Player p)
{
    DrawTexture(hudTexturePanel, static_cast<float>(GetScreenWidth()-(GetScreenWidth()/5)*1.54),0 ,WHITE);
    DrawTexture(healthbarBaseText, 5 , static_cast<float>(GetScreenHeight()) - 20 , WHITE);
    float currentHPBarWidth=(49-((p.getPlayerMaxHealth()-(p.getPlayerHealth()))/p.getPlayerMaxHealth()*49));
    DrawTextureRec(healthbarOverText,{0,0,currentHPBarWidth,17}, {19 , static_cast<float>(GetScreenHeight()) - 20}, WHITE);
    DrawTexture(towerCreateButton,600,50,WHITE);
}

void hudUnload()
{
    UnloadTexture(hudTexturePanel);
}