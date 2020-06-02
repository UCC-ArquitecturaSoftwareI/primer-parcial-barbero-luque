//
// Created by Francisco on 21/4/2020.
//

#include "torre.h"
#include "projectile.h"

tower::tower(int a, std::string b, const Vector2 &towerPos, std::string patch, std::string patch2) : tower_pos(towerPos) {
    cost=a;
    name=b;
    towerTextureBase = LoadTexture(patch.c_str());
    towerTextureTop = LoadTexture(patch2.c_str());
}

projectile tower::fireProj(Enemies &e) {
    if(currentCooldown==0)
    {
        Texture2D projectileText=LoadTexture("resources/Missile.png");
        projectile temp(e,10,tower_pos,projectileText,10);
        currentCooldown=maxCooldown;
        return temp;
        }
    else{
        currentCooldown--;
        projectile temp;
        return temp;
    }

}

void tower::setTowerPosition(Vector2 position) {
    if ( IsMouseButtonPressed(MOUSE_LEFT_BUTTON) ){
        position = GetMousePosition();
        tower_pos.x = position.x;
        tower_pos.y = position.y;
    }
}
