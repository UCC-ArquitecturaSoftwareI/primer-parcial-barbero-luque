//
// Created by Francisco on 24/4/2020.
//

static int framesCounter;
static int finishScreen;
#include "hud.cpp"
void InitGameplayScreen(void)
{
    framesCounter = 0;
    finishScreen = 0;
    hudInit();
}

void UpdateGameplayScreen(void)
{


}

void DrawGameplayScreen(void)
{
    hudDraw();
}

void UnloadGameplayScreen(void)
{

}

int FinishGameplayScreen(void)
{
    return finishScreen;
}