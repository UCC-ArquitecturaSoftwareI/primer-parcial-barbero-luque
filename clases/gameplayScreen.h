//
// Created by Francisco on 24/4/2020.
//

#ifndef RAYLIBTEMPLATE_GAMEPLAYSCREEN_H
#define RAYLIBTEMPLATE_GAMEPLAYSCREEN_H
static int framesCounter;
static int finishScreen;
#include "hud.h"

void InitGameplayScreen();
void UpdateGameplayScreen();
int FinishGameplayScreen();
void UnloadGameplayScreen();
void DrawGameplayScreen();

#endif //RAYLIBTEMPLATE_GAMEPLAYSCREEN_H
