//
// Created by Francisco on 24/4/2020.
//

#include "gameplayScreen.h"


void InitGameplayScreen() {
    framesCounter = 0;
    finishScreen = 0;
    mapInit();
    hudInit();
}

void UpdateGameplayScreen() {


}

void DrawGameplayScreen() {
    mapDraw();
    hudDraw();
}





void UnloadGameplayScreen() {

}

int FinishGameplayScreen() {
    return finishScreen;
}

