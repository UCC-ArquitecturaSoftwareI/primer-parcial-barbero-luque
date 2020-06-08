//
// Created by Francisco on 24/4/2020.
//

#include <list>
#include "gameplayScreen.h"
#include "enemies.h"
#include "player.h"
#include "random"
#include "torre.h"
//#include "projectile.h"
#include "rendering.h"
EasyEnemie builderEasy;
MediumEnemie builderMedium;
HardEnemie builderHard;

Cuartel cuartelEasy( builderEasy );
Cuartel cuartelMedium( builderMedium );
Cuartel cuartelHard( builderHard );

rendering<tower> renderer;
int currenthealth=100;
int currentlevel=1;
int currentdX;
int currentdY;
Player p;
int currentPlayerStatus=0; //0=GameplayNormal, 1=ColocandoTorre
Vector2 startpos{5,85 };
Vector2 ButtonTowerCreatePos{600,50};

Texture2D currentTowerText1;
Texture2D currentTowerText2;

std::list<tower> activeTowers;

void InitGameplayScreen() {
    framesCounter = 0;
    finishScreen = 0;
    mapInit();
    hudInit();
    currentPlayerStatus=0;
    p.startplayer();
    switch (currentlevel){
        case 1:
            cuartelEasy.construct();
            cuartelMedium.construct();
            cuartelHard.construct();
        case 2:
            ;


    }
}

void UpdateGameplayScreen() {
    builderEasy.buildMovement();
    builderMedium.buildMovement();
    builderHard.buildMovement();
    switch(currentlevel){
        case 1:
            if(framesCounter%60==0 && framesCounter<=900)
            {
                currentdX=1;
                currentdY=0;
            }
    }

 for(auto i=activeTowers.begin();i!=activeTowers.end();++i)
    {
        /*aux=i->fireProj(activeEnemies.front());
        if (aux.getSpeed()!=0)
        {
            activeProjectiles.push_back(aux);
        }*/
    }
    if (currentPlayerStatus==1 && IsMouseButtonDown(MOUSE_LEFT_BUTTON) && GetMousePosition().x<(GetScreenWidth()-(GetScreenWidth()/5)*1.54)){

        tower tnew(100,"Torre1",GetMousePosition(),"resources/TowerBase.png","resources/TowerTop.png");
        activeTowers.push_back(tnew);
        UnloadTexture(currentTowerText2);
        UnloadTexture(currentTowerText1);
        currentPlayerStatus=0;
    }
    if(currentPlayerStatus==1 && IsMouseButtonDown(MOUSE_RIGHT_BUTTON)){
        currentPlayerStatus=0;
    }

    if(IsMouseButtonDown(MOUSE_LEFT_BUTTON) && ((std::abs(GetMousePosition().x-ButtonTowerCreatePos.x))<64 && std::abs((GetMousePosition().y-ButtonTowerCreatePos.y))<64))
    {
        //if p.getPlayerMoney()>25;
        //        p.takeMoney(25);
        currentPlayerStatus=1;
        currentTowerText1=LoadTexture("resources/TowerBase.png");
        currentTowerText2=LoadTexture("resources/TowerTop.png");
    }


framesCounter++;
}

void DrawGameplayScreen() {
    mapDraw();
    hudDraw(p);
    builderEasy.buildMovement();
    builderEasy.buildDraw();
    //builderMedium.buildMovement();
    //builderMedium.buildDraw();
    //builderHard.buildMovement();
    //builderHard.buildDraw();
    if(currentPlayerStatus==1)
    {
        renderer.drawPhantomTextureTower(currentTowerText1,currentTowerText2,GetMousePosition().x,GetMousePosition().y);
    }
    for(auto i=activeTowers.begin(); i!=activeTowers.end(); ++i)
    {
        i->draw();
    }
    //DrawText(reinterpret_cast<const char *>(playerhealth), 80, static_cast<float>(GetScreenHeight()) - 20, 14 , BLACK);
}





void UnloadGameplayScreen() {

}

int FinishGameplayScreen() {
    return finishScreen;
}

