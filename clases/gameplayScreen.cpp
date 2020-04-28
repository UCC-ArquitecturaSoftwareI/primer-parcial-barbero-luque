//
// Created by Francisco on 24/4/2020.
//

#include <list>
#include "gameplayScreen.h"
#include "enemies.h"
#include "player.h"

std::list<enemies> activeEnemies;

int currenthealth=100;
int currentlevel=1;
int currentdX;
int currentdY;

Vector2 startpos{5,128 };

void InitGameplayScreen() {
    framesCounter = 0;
    finishScreen = 0;
    mapInit();
    hudInit();

    switch (currentlevel){
        case 1:
            for(int i=0;i<2;i++){
                enemies currentenemy(1, startpos,"resources/towerDefense_tile245.png");
                activeEnemies.push_back(currentenemy);
            }
            currentdX=1;
            currentdY=0;

        case 2:
            ;


    }

}

void UpdateGameplayScreen() {
    for(auto i=activeEnemies.begin(); i!=activeEnemies.end() ; ++i)
    {
        if(i->getenemie_pos().x==290 && i->getenemie_pos().y<330)
        {
            i->move_y(1);
        }
        else if(i->getenemie_pos().x==500)
        {
            i->move_y(-1);
            if(i->getenemie_pos().y<0)
            {
               // activeEnemies.remove(*i);
                pdamage(5);

            }
        }
        else
        {
            i->move_x(1);
        }
    }
}

void DrawGameplayScreen() {
    mapDraw();
    hudDraw();
    for(auto i=activeEnemies.begin(); i!=activeEnemies.end() ; ++i)
    {
        i->draw();
    }
    DrawText(reinterpret_cast<const char *>(playerhealth), 80, static_cast<float>(GetScreenHeight()) - 20, 14 , BLACK);

}





void UnloadGameplayScreen() {

}

int FinishGameplayScreen() {
    return finishScreen;
}

