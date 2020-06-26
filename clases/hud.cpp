//
// Created by Francisco on 24/4/2020.
//
#include <string>
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
    testing=LoadTexture("resources/background-menu.png" );
}

void menuDraw(){
    DrawRectangle( 0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);
    DrawText("START", static_cast<float>(GetScreenWidth()) - 450, static_cast<float>(GetScreenHeight()) - 350, 20, WHITE);
    //DrawText("OPTIONS", static_cast<float>(GetScreenWidth()) - 450, static_cast<float>(GetScreenHeight()) - 325, 20, WHITE);
    DrawText("CLOSE", static_cast<float>(GetScreenWidth()) - 450, static_cast<float>(GetScreenHeight()) - 300, 20, WHITE);
    DrawText("Made by Francisco Luque y Agustin Barbero", static_cast<float>(GetScreenWidth()) - 795, static_cast<float>(GetScreenHeight()) - 20, 10, WHITE);

}

void hudDraw(Player p){
    DrawTexture(hudTexturePanel, static_cast<float>(GetScreenWidth()-(GetScreenWidth()/5)*1.54),0 ,WHITE);
    DrawTexture(healthbarBaseText, 5 , static_cast<float>(GetScreenHeight()) - 20 , WHITE);
    float PmaxH=p.getPlayerMaxHealth();
    float pH=p.getPlayerHealth();
    float currentHPBarWidth=(49-((PmaxH-pH)/PmaxH*49));
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

    std::string s = "$" + std::to_string(p.getPlayerMoney());
    char const *pchar = s.c_str();

    DrawText(pchar, 5, static_cast<float>(GetScreenHeight()) - 45, 20, RED);

}

void hudUnload()
{
    UnloadTexture(hudTexturePanel);
}
