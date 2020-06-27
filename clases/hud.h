//
// Created by Francisco on 24/4/2020.
//

#ifndef RAYLIBTEMPLATE_HUD_H
#define RAYLIBTEMPLATE_HUD_H
#include <raylib.h>
#include "player.h"
#include "torre.h"

void hudInit();
void hudDraw(Player p);

void menuInit();
void menuDraw();

bool isTowerSelected(std::list<tower> tList);
tower* getSelectedTower(std::list<tower> tList);

void hudUnload();

#endif //RAYLIBTEMPLATE_HUD_H
