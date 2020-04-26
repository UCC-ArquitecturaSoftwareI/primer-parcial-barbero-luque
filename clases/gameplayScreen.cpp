//
// Created by Francisco on 24/4/2020.
//

#include "gameplayScreen.h"


void InitGameplayScreen() {
    framesCounter = 0;
    finishScreen = 0;
    hudInit();
    mapInit();
}

void UpdateGameplayScreen() {


}

void DrawGameplayScreen() {
    hudDraw();
    mapDraw();
}





void UnloadGameplayScreen() {

}

int FinishGameplayScreen() {
    return finishScreen;
}

