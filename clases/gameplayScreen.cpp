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

rendering renderer;
int currenthealth = 100;
int currentlevel = 1;
int currentdX;
int currentdY;
Player p;
int currentPlayerStatus = 0; //0=GameplayNormal, 1=ColocandoTorre
Vector2 startpos{5, 85};
Vector2 ButtonTowerCreatePos{600, 50};

std::string currentTowerText1;
std::string currentTowerText2;

std::list<tower> activeTowers;
//std::list<EnemieBuilder> activeEnemies;
std::list<projectile> activeProjectiles;

void InitGameplayScreen() {
    framesCounter = 0;
    finishScreen = 0;
    mapInit();
    hudInit();
    currentPlayerStatus = 0;
    p.startplayer();
    switch (currentlevel) {
        case 1:
            for(int i=0;i<=2;i++){
                enemies.push_front(cuartelMedium.construct());
                enemies.push_front(cuartelEasy.construct());
                enemies.push_front(cuartelHard.construct());
            }
            currentdX = 1;
            currentdY = 0;
        case 2:;


    }
}

void UpdateGameplayScreen() {

    switch (currentlevel) {
        case 1:
            if (framesCounter % 60 == 0 && framesCounter <= 300) {

            }
            if (framesCounter % 60 == 0 && framesCounter > 300 && framesCounter <= 600) {

            }
            if (framesCounter % 60 == 0 && framesCounter > 600 && framesCounter <= 900) {

            }

    }
    for (auto i = activeTowers.begin(); i != activeTowers.end(); ++i) {
        if (i->cooldownTick() == 1) {
            i->fireProj(activeProjectiles);

        }
    }
    if (currentPlayerStatus == 1 && IsMouseButtonDown(MOUSE_LEFT_BUTTON) &&
        GetMousePosition().x < (GetScreenWidth() - (GetScreenWidth() / 5) * 1.54) &&
        !checkCollision({GetMousePosition().x,GetMousePosition().y,32,32},activeTowers)) {

        tower tnew(100, "Torre1", GetMousePosition(), "resources/TowerBase.png", "resources/TowerTop.png", enemies,renderer);
        activeTowers.push_back(tnew);
        currentPlayerStatus = 0;
    }
    if (currentPlayerStatus == 1 && IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
        currentPlayerStatus = 0;
    }

    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && ((std::abs(GetMousePosition().x - ButtonTowerCreatePos.x)) < 64 &&
                                                 std::abs((GetMousePosition().y - ButtonTowerCreatePos.y)) < 64)) {
        //if p.getPlayerMoney()>25;
        //        p.takeMoney(25);
        currentPlayerStatus = 1;
        currentTowerText1 = "resources/TowerBase.png";
        currentTowerText2 = "resources/TowerTop.png";
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

    if(framesCounter%255==0)
    {

        for (auto i = enemies.begin(); i != enemies.end(); ++i) {
            if ((*i)->gettoDie()) {
                enemies.remove(*i);
            }
        }
    }
    framesCounter++;
}

void DrawGameplayScreen() {
    mapDraw();
    hudDraw(p);

    for (auto i = activeTowers.begin(); i != activeTowers.end(); ++i) {
        i->draw();
    }
    for (auto i = activeProjectiles.begin(); i != activeProjectiles.end(); ++i) {
        i->draw();
    }
    for (auto i = enemies.begin(); i != enemies.end(); ++i) {
        (*i)->draw();
    }
    if (currentPlayerStatus == 1) {
        if(checkCollision({GetMousePosition().x,GetMousePosition().y,32,32},activeTowers))
        {
            renderer.drawPhantomTextureError(currentTowerText1, currentTowerText2, GetMousePosition().x,
                                             GetMousePosition().y);
        }
        else
        {

            renderer.drawPhantomTextureTower(currentTowerText1, currentTowerText2, GetMousePosition().x,
                                             GetMousePosition().y);
        }
    }
    //DrawText(reinterpret_cast<const char *>(playerhealth), 80, static_cast<float>(GetScreenHeight()) - 20, 14 , BLACK);
}


void UnloadGameplayScreen() {

}

int FinishGameplayScreen() {
    return finishScreen;
}
