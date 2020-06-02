//
// Created by Francisco on 24/4/2020.
//

#ifndef RAYLIBTEMPLATE_WINDOWCONTROLLER_H
#define RAYLIBTEMPLATE_WINDOWCONTROLLER_H
#include <raylib.h>

#include "gameplayScreen.h"


const int screenWidth = 800;
const int screenHeight = 450;


class windowcontroller{
public:
    Player p;
    void start();
    static void UpdateDrawFrame();
};
#endif //RAYLIBTEMPLATE_WINDOWCONTROLLER_H
