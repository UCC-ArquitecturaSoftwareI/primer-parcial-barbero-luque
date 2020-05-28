//
// Created by Francisco on 21/4/2020.
//

#include "torre.h"

tower::tower(int a, std::string b, const Vector2 &towerPos, std::string patch) : tower_pos(towerPos) {
    cost=a;
    name=b;
    towerTexture = LoadTexture(patch.c_str());
}

void tower::fireProj(enemies) {

}

void tower::setTowerPosition(Vector2 position) {
    if ( IsMouseButtonPressed(MOUSE_LEFT_BUTTON) ){
        position = GetMousePosition();
        tower_pos.x = position.x;
        tower_pos.y = position.y;
    }
}
