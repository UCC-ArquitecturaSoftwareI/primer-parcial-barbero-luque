//
// Created by Francisco on 21/4/2020.
//

#include "torre.h"
#include "projectile.h"

/**
 *  Constructor de Tower
 */
tower::tower(int a, std::string b, const Vector2 &towerPos, std::string patch, std::string patch2, std::list<Enemy*> &enL) : tower_pos(
        towerPos), eList(enL), CurrentTarget(findInRange()){
    cost = a;
    name = b;
    towerTextureBase = patch;
    towerTextureTop = patch2;
    projectileText = "resources/Missile.png";
    damage=20;
}

/**
 *  Dada la lista de misiles, dispara un misil a un enemigo en la lista de enemigos, poniendolo al misil en la lista.
 *  Prioriza enemigos cercanos. Utiliza templatemethod para propiedades de cada torre.
 */
void tower::fireProj(std::list<projectile> &activeProjectiles) {
    if(eList.empty())
    {
        return;
    }
    else
    {
    if(CurrentTarget->gettoDie()==false)
        activeProjectiles.emplace_back(CurrentTarget, 0.05, tower_pos, &projectileText, damage,eList);
        //TemplateMethod para mayores funcionalidades.
        this->hookadditionalFireProperties(activeProjectiles);
    if(CurrentTarget->gettoDie()==true)
    {
            CurrentTarget=findInRange();
            activeProjectiles.emplace_back(CurrentTarget, 0.05, tower_pos, &projectileText, damage,eList);
            //TemplateMethod para mayores funcionalidades.
            this->hookadditionalFireProperties(activeProjectiles);
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
/**
 *  Retorna 1 si esta lista para disparar, y reinicia el conteo, de lo contrario retorna 0 y reduce el cooldown.
 */
int tower::cooldownTick() {
    if (currentCooldown == 0) {
        currentCooldown = maxCooldown;
        return 1;
    } else {
        currentCooldown--;
        return 0;
    }
}
/**
 *  Dibuja la torre, llamando al renderer y a un calculo para ver a donde apunta el tope.
 */
void tower::draw() {
    float angle=fast_atan2(CurrentTarget->getEnemie_pos().y-tower_pos.y,CurrentTarget->getEnemie_pos().x-tower_pos.x);
    renderer.drawTower(towerTextureBase, towerTextureTop, tower_pos.x, tower_pos.y,angle);
}
/**
 *  Encuentra un enemigo cerca en la lista de enemigos. de no haber, retorna un puntero al primero de la lista vivo, de no
 *  haber, retorna un puntero al ultimo de la lista.
 */
Enemy* tower::findInRange() {
    for(auto i=eList.begin();i!=eList.end();++i)
    {
        if(abs((*i)->getEnemie_pos().x-tower_pos.x)<100 && abs((*i)->getEnemie_pos().y-tower_pos.y)<100 && !(*i)->gettoDie())
            return (*i);
    }
    for(auto i=eList.begin();i!=eList.end();++i)
    {
        if(!(*i)->gettoDie())
            return (*i);
    }
    auto i = eList.end();
    return *--i;
}
