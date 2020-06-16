//
// Created by Francisco on 21/4/2020.
//

#include "torre.h"
#include "projectile.h"

tower::tower(int a, std::string b, const Vector2 &towerPos, std::string patch, std::string patch2) : tower_pos(
        towerPos) {
    cost = a;
    name = b;
    towerTextureBase = LoadTexture(patch.c_str());
    towerTextureTop = LoadTexture(patch2.c_str());
    projectileText = LoadTexture("resources/Missile.png");
}

void tower::fireProj(EnemieBuilder &e, std::list<projectile> &activeProjectiles) {

    activeProjectiles.emplace_back(e, 0.01, tower_pos, &projectileText, 10);
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
    renderer.drawTower(towerTextureBase, towerTextureTop, tower_pos.x, tower_pos.y);
}
