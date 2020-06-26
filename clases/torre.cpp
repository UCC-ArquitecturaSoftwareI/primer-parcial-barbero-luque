//
// Created by Francisco on 21/4/2020.
//

#include "torre.h"
#include "projectile.h"

tower::tower(int a, std::string b, const Vector2 &towerPos, std::string patch, std::string patch2, std::list<Enemy*> &enL) : tower_pos(
        towerPos), eList(enL), CurrentTarget(findInRange()){
    cost = a;
    name = b;
    towerTextureBase = patch;
    towerTextureTop = patch2;
    projectileText = "resources/Missile.png";
    damage=20;
}

void tower::fireProj(std::list<projectile> &activeProjectiles) {
    if(eList.empty())
    {
        return;
    }
    else
    {
    if(CurrentTarget->gettoDie()==false)
        activeProjectiles.emplace_back(CurrentTarget, 0.05, tower_pos, &projectileText, damage,eList);
    if(CurrentTarget->gettoDie()==true)
    {
            CurrentTarget=findInRange();
            activeProjectiles.emplace_back(CurrentTarget, 0.05, tower_pos, &projectileText, damage,eList);
    }
    }
}

void tower::setTowerPosition(Vector2 position) {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        position = GetMousePosition();
        tower_pos.x = position.x;
        tower_pos.y = position.y;
    }
}

int tower::cooldownTick() {
    if (currentCooldown == 0) {
        currentCooldown = maxCooldown;
        return 1;
    } else {
        currentCooldown--;
        return 0;
    }
}

void tower::draw() {
    float angle=fast_atan2(CurrentTarget->getEnemie_pos().y-tower_pos.y,CurrentTarget->getEnemie_pos().x-tower_pos.x);
    renderer.drawTower(towerTextureBase, towerTextureTop, tower_pos.x, tower_pos.y,angle);
}

Enemy* tower::findInRange() {
    for(auto i=eList.begin();i!=eList.end();++i)
    {
        if((*i)->getEnemie_pos().x-tower_pos.x<400 && (*i)->getEnemie_pos().y-tower_pos.y<400 && !(*i)->gettoDie())
            return (*i);
    }
    auto i = eList.end();
    return *--i;
}

