//
// Created by Francisco on 24/4/2020.
//
#include "hud.h"

Texture2D hudTexturePanel;
Rectangle hudRightPanel;

Texture2D healthbarBaseText;

Texture2D towerCreateButton;

Texture2D healthbarOverText;

Texture2D testing;


void hudInit()
{
    hudRightPanel={static_cast<float>(GetScreenWidth()-(GetScreenWidth()/5)),0,static_cast<float>(GetScreenWidth()/5*2), static_cast<float>(GetScreenHeight())};
    hudTexturePanel = LoadTexture("resources/HudPanelRight.png");

    healthbarBaseText=LoadTexture("resources/health_bar_decoration.png");
    healthbarOverText=LoadTexture("resources/health_bar.png");

    towerCreateButton=LoadTexture("resources/TowerCreateButton.png");
}

void menuInit(){
    testing=LoadTexture("resources/background-menu.png");
}

void menuDraw(){
    DrawTexture(testing, 0,0 ,WHITE);

}

void hudDraw(Player p)
{
    DrawTexture(hudTexturePanel, static_cast<float>(GetScreenWidth()-(GetScreenWidth()/5)*1.54),0 ,WHITE);
    DrawTexture(healthbarBaseText, 5 , static_cast<float>(GetScreenHeight()) - 20 , WHITE);
    float currentHPBarWidth=(49-((p.getPlayerMaxHealth()-(p.getPlayerHealth()))/p.getPlayerMaxHealth()*49));
    DrawTextureRec(healthbarOverText,{0,0,currentHPBarWidth,17}, {19 , static_cast<float>(GetScreenHeight()) - 20}, WHITE);
    DrawTexture(towerCreateButton, static_cast<float>(GetScreenWidth()) - 200,static_cast<float>(GetScreenHeight()) - 400,WHITE);
    DrawTexture(towerCreateButton,static_cast<float>(GetScreenWidth()) - 200,static_cast<float>(GetScreenHeight()) - 330,WHITE);
    DrawTexture(towerCreateButton,static_cast<float>(GetScreenWidth()) - 200,static_cast<float>(GetScreenHeight()) - 260,WHITE);
    DrawText("Normal", static_cast<float>(GetScreenWidth()) - 130, static_cast<float>(GetScreenHeight()) - 400, 20, BLUE);
    DrawText("$100", static_cast<float>(GetScreenWidth()) - 130, static_cast<float>(GetScreenHeight()) - 380, 20, GREEN);
    DrawText("Fuerte", static_cast<float>(GetScreenWidth()) - 130, static_cast<float>(GetScreenHeight()) - 330, 20, BLUE);
    DrawText("$200", static_cast<float>(GetScreenWidth()) - 130, static_cast<float>(GetScreenHeight()) - 310, 20, GREEN);
    DrawText("Area", static_cast<float>(GetScreenWidth()) - 130, static_cast<float>(GetScreenHeight()) - 260, 20, BLUE);
    DrawText("$300", static_cast<float>(GetScreenWidth()) - 130, static_cast<float>(GetScreenHeight()) - 240, 20, GREEN);

    DrawText("$300", 5, static_cast<float>(GetScreenHeight()) - 45, 20, RED);

}

void hudUnload()
{
    UnloadTexture(hudTexturePanel);
}