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

std::list<Enemy*> enemies;

EasyEnemie builderEasy;
MediumEnemie builderMedium;
HardEnemie builderHard;

Cuartel cuartelEasy(builderEasy);
Cuartel cuartelMedium(builderMedium);
Cuartel cuartelHard(builderHard);

rendering &renderer=rendering::get();
int currenthealth = 100;
int currentlevel = 1;
int currentStatus = 0; //0=Menu , 1=Gameplay, 2=Defeat.
int currentdX;
int currentdY;
Player p;
int currentPlayerStatus = 0; //0=GameplayNormal, 1=ColocandoTorreNormal, 2=ColocandoTorreFuerte, 3=ColocandoTorreEnArea
Vector2 startpos{5, 85};
Vector2 ButtonTowerCreatePos{635, 85};
Vector2 ButtonTowerStrongCreatePos{635, 155};
Vector2 ButtonTowerAreaCreatePos{635, 225};

std::string currentTowerText1;
std::string currentTowerText2;

std::list<tower*> activeTowers;
//std::list<EnemieBuilder> activeEnemies;
std::list<projectile> activeProjectiles;

int defeatedEnemies=0;

void InitGameplayScreen() {
    framesCounter = 0;
    finishScreen = 0;
    mapInit();
    hudInit();
    menuInit();


    currentPlayerStatus = 0;
    p.startplayer();
    switch (currentlevel) {
        case 1:
            for(int i=0;i<=2;i++){
                /*enemies.push_front(cuartelMedium.construct());
                enemies.push_front(cuartelEasy.construct());
                enemies.push_front(cuartelHard.construct());*/
            }
            currentdX = 1;
            currentdY = 0;
        case 2:;


    }
}

/**
 *  Loop de Lógica del Juego
 */
void UpdateGameplayScreen() {
    if(currentStatus==1)
    {


    switch (currentlevel) {
        case 1:
            if (framesCounter % 60 == 0 && framesCounter <= 300) {
                enemies.push_front(cuartelEasy.construct());
            }
            if (framesCounter % 60 == 0 && framesCounter > 300 && framesCounter <= 600) {
                enemies.push_front(cuartelMedium.construct());
            }
            if (framesCounter % 60 == 0 && framesCounter > 600 && framesCounter <= 900) {
                enemies.push_front(cuartelHard.construct());
            }

            if(framesCounter%60==0  && framesCounter > 1200)
            {
                        enemies.push_front(cuartelEasy.construct());
            }
            if(framesCounter%90==0  && framesCounter > 1200)
                enemies.push_front(cuartelMedium.construct());
            if(framesCounter%115==0  && framesCounter > 1200)
                enemies.push_front(cuartelHard.construct());
    }
    for (auto i = activeTowers.begin(); i != activeTowers.end(); ++i) {
        if ((*i)->cooldownTick() == 1) {
            (*i)->fireProj(activeProjectiles);
        }
    }
    if (currentPlayerStatus == 1 && IsMouseButtonDown(MOUSE_LEFT_BUTTON) &&
        GetMousePosition().x < (GetScreenWidth() - (GetScreenWidth() / 5) * 1.54) &&
        !checkCollision({GetMousePosition().x,GetMousePosition().y,32,32},activeTowers) && p.getPlayerMoney()>=100) {
        activeTowers.push_back(new NormalTower(100, "Torre1", GetMousePosition(), "resources/TowerBase.png", "resources/TowerTop.png", enemies));
        p.takeMoney(100);
        currentPlayerStatus = 0;
    }
        if (currentPlayerStatus == 2 && IsMouseButtonDown(MOUSE_LEFT_BUTTON) &&
            GetMousePosition().x < (GetScreenWidth() - (GetScreenWidth() / 5) * 1.54) &&
            !checkCollision({GetMousePosition().x,GetMousePosition().y,32,32},activeTowers ) && p.getPlayerMoney()>=200) {
           activeTowers.push_back(new StrongTower(200, "Torre2", GetMousePosition(), "resources/TowerBase.png", "resources/TowerTopStrong.png", enemies));
            p.takeMoney(200);
            currentPlayerStatus = 0;
        }
        if (currentPlayerStatus == 3 && IsMouseButtonDown(MOUSE_LEFT_BUTTON) &&
            GetMousePosition().x < (GetScreenWidth() - (GetScreenWidth() / 5) * 1.54) &&
            !checkCollision({GetMousePosition().x,GetMousePosition().y,32,32},activeTowers ) && p.getPlayerMoney()>=300) {
            activeTowers.push_back(new AreaTower(200, "Torre2", GetMousePosition(), "resources/TowerBase.png", "resources/TowerTopArea.png", enemies));
            p.takeMoney(300);
            currentPlayerStatus = 0;
        }
    if (currentPlayerStatus == 1 && IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
            currentPlayerStatus = 0;
        }
    if (currentPlayerStatus == 2 && IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
            currentPlayerStatus = 0;
        }
    if (currentPlayerStatus == 3 && IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
            currentPlayerStatus = 0;
        }

    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && ((std::abs(GetMousePosition().x - ButtonTowerCreatePos.x)) < 32 &&
                                                 std::abs((GetMousePosition().y - ButtonTowerCreatePos.y)) < 32)) {
        //if p.getPlayerMoney()>25;
        //        p.takeMoney(25);
        currentPlayerStatus = 1;
        currentTowerText1 = "resources/TowerBase.png";
        currentTowerText2 = "resources/TowerTop.png";
    }
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && ((std::abs(GetMousePosition().x - ButtonTowerStrongCreatePos.x)) < 32 &&
                                                     std::abs((GetMousePosition().y - ButtonTowerStrongCreatePos.y)) < 32)) {

            currentPlayerStatus = 2;
            currentTowerText1 = "resources/TowerBase.png";
            currentTowerText2 = "resources/TowerTopStrong.png";
        }
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && ((std::abs(GetMousePosition().x - ButtonTowerAreaCreatePos.x)) < 32 &&
                                                     std::abs((GetMousePosition().y - ButtonTowerAreaCreatePos.y)) < 32)) {

            currentPlayerStatus = 3;
            currentTowerText1 = "resources/TowerBase.png";
            currentTowerText2 = "resources/TowerTopArea.png";
        }

    for (auto i = activeProjectiles.begin(); i != activeProjectiles.end(); ++i) {
        if (i->gettoDie()) {
            activeProjectiles.erase(i);
        }
        i->move();
    }

    for (auto i = enemies.begin(); i != enemies.end(); ++i) {
        if((*i)->gettoDie() == false )
            (*i)->startMove();
    }
    for (auto i = enemies.begin(); i != enemies.end(); ++i) {
        if((*i)->gettoDie() == false )
            if((*i)->getEnemie_pos().y<=0 )
            {
               p.pdamage((*i)->getDamage());
               (*i)->setToDie();
            }
    }

    if(framesCounter%255==0)
    {

        for (auto i = enemies.begin(); i != enemies.end(); ++i) {
            if ((*i)->gettoDie()) {
                if((*i)->getHP()<=0)
                {
                    p.giveMoney((*i)->getLevel()*100);
                    defeatedEnemies++;
                }
                enemies.erase(i);
            }
        }
    }
        //std::cout<<"PLAYER HEALTH: "<<p.getPlayerHealth()<<std::endl;

//std::cout<<"PLAYER MONEY: "<<p.getPlayerMoney()<<" PLAYER STATUS: "<<currentPlayerStatus<<std::endl;
    framesCounter++;
    if(p.getPlayerHealth()==0)
        currentStatus=2;
    }
    else if(currentStatus==0)
    {
        //std::cout<<GetMousePosition().x<<" , "<<GetMousePosition().y<<std::endl;
        if(GetMousePosition().x-(380)<=50 && std::abs(GetMousePosition().y-(100)) <=20
        && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            currentStatus=1;

        if(GetMousePosition().x-(380)<=50 && std::abs(GetMousePosition().y-(150)) <=20
        && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            CloseWindow();
    }
    else if(currentStatus==2)
    {
        if(IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            CloseWindow();
        }
    }

}

/**
 *  Loop de Dibujo del Juego
 */
void DrawGameplayScreen() {
    if( currentStatus == 1  || currentStatus==2) {
        mapDraw();
        hudDraw(p);

        for (auto i = activeTowers.begin(); i != activeTowers.end(); ++i) {
            (*i)->draw();
        }
        for (auto i = activeProjectiles.begin(); i != activeProjectiles.end(); ++i) {
            i->draw();
        }
        for (auto i = enemies.begin(); i != enemies.end(); ++i) {
            if (!(*i)->gettoDie())
                (*i)->draw();
        }
        if (currentPlayerStatus == 1) {
            if (checkCollision({GetMousePosition().x, GetMousePosition().y, 32, 32}, activeTowers)) {
                renderer.drawPhantomTextureError(currentTowerText1, currentTowerText2, GetMousePosition().x,
                                                 GetMousePosition().y);
            } else {

                renderer.drawPhantomTextureTower(currentTowerText1, currentTowerText2, GetMousePosition().x,
                                                 GetMousePosition().y);
            }
        }
        if (currentPlayerStatus == 2) {
            if (checkCollision({GetMousePosition().x, GetMousePosition().y, 32, 32}, activeTowers)) {
                renderer.drawPhantomTextureError(currentTowerText1, currentTowerText2, GetMousePosition().x,
                                                 GetMousePosition().y);
            } else {

                renderer.drawPhantomTextureTower(currentTowerText1, currentTowerText2, GetMousePosition().x,
                                                 GetMousePosition().y);
            }
        }
        if (currentPlayerStatus == 3) {
            if (checkCollision({GetMousePosition().x, GetMousePosition().y, 32, 32}, activeTowers)) {
                renderer.drawPhantomTextureError(currentTowerText1, currentTowerText2, GetMousePosition().x,
                                                 GetMousePosition().y);
            } else {

                renderer.drawPhantomTextureTower(currentTowerText1, currentTowerText2, GetMousePosition().x,
                                                 GetMousePosition().y);
            }
        }
        //DrawText(reinterpret_cast<const char *>(playerhealth), 80, static_cast<float>(GetScreenHeight()) - 20, 14 , BLACK);
    }
    else if(currentStatus==0){
        menuDraw();
    }
    if(currentStatus==2)
    {
        std::string s = "Enemigos Derrotados:" + std::to_string(defeatedEnemies);
        char const *pchar = s.c_str();
        DrawText("PERDISTE",200,150,60,RED);
        DrawText(pchar,200,275,20,BLACK);
        DrawText("Presiona click izquierdo para salir.",200,340,20,BLACK);
    }
}


void UnloadGameplayScreen() {

}

int FinishGameplayScreen() {
    return finishScreen;
}
