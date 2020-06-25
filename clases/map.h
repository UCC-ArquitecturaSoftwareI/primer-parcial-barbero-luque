//
// Created by Agustin on 26/4/2020.
//

#ifndef RAYLIBTEMPLATE_MAP_H
#define RAYLIBTEMPLATE_MAP_H

#include <raylib.h>
#include "torre.h"

void mapInit();
void mapDraw();

bool checkCollision(Rectangle a, std::list<tower> &towers);
void mapUnload();

#endif //RAYLIBTEMPLATE_MAP_H
