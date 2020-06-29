//
// Created by Agustin on 29/4/2020.
//

#ifndef RAYLIBTEMPLATE_RENDERING_H
#define RAYLIBTEMPLATE_RENDERING_H

#include <list>
#include <iostream>
#include "raylib.h"
#include <map>
#include <unordered_map>
#include <math.h>

class rendering {
private:
    rendering(){}


    int currentframe = 0;
    std::unordered_map<std::string, Texture2D> textMap;

    Texture2D &getTexture(std::string s)  //Flyweight para pasar las texturas dentro del Renderer
    {
        auto myText=textMap.find(s);
        if (myText==textMap.end())
        {

            textMap.emplace(s,LoadTexture(s.c_str()));
        }

        return textMap[s];

    }
public:

    static rendering &get()  //Singleton para tener un solo renderer global.
    {
        static rendering renderer;
        return renderer;
    }

    /*void drawEnemy(std::string a, float x, float y) {
        DrawTexture(getTexture(a), x - getTexture(a).width / 2, y - getTexture(a).height / 2,  WHITE);
    }*/
    /**
 *  Función dedicada a dibujar cada enemigo. Se le deben pasar el path a la textura, las coordenadas x e y, y la rotacion.
 */

    void drawEnemy(std::string a, float x, float y, float rot) {
        //DrawTextureEx(getTexture(a), {x - getTexture(a).width / 2, y - getTexture(a).height / 2}, rot, 1, WHITE);
        DrawTexturePro(getTexture(a),
                       {0,0,static_cast<float>(getTexture(a).width),static_cast<float>(getTexture(a).height)},
                       {x ,y,64,64},
                       {32,32},rot,WHITE);
    }
/**
 *  Función dedicada a dibujar una torre a ser colocada correctamente
 *  Se le deben pasar el path a las texturas, las coordenadas x e y.
 */
    void drawPhantomTextureTower(std::string base, std::string tope, float x, float y) {
        DrawTexture(getTexture(base), x - getTexture(base).width / 2, y - getTexture(base).height / 2, GREEN);
        DrawTexture(getTexture(tope), x - getTexture(tope).width / 2, y - getTexture(tope).height / 2, GREEN);
    }

    /**
 *  Función dedicada a dibujar una torre a ser colocada incorrectamente
 *  Se le deben pasar el path a las texturas, las coordenadas x e y.
 */

    void drawPhantomTextureError(std::string base, std::string tope, float x, float y) {
        DrawTexture(getTexture(base), x - getTexture(base).width / 2, y - getTexture(base).height / 2, RED);
        DrawTexture(getTexture(tope), x - getTexture(tope).width / 2, y - getTexture(tope).height / 2, RED);
    }
    /**
 *  Función dedicada a dibujar una torre
 *  Se le deben pasar el path a las texturas, las coordenadas x e y, y la rotacion del tope.
 */
    void drawTower(std::string base, std::string tope, float x, float y, float rot) {
        DrawTexture(getTexture(base), x - getTexture(base).width / 2, y - getTexture(base).height / 2, WHITE);
        //DrawTextureEx(getTexture(tope), {x - getTexture(tope).width / 2, y - getTexture(tope).height / 2},rot*3.14,1, WHITE);
        DrawTexturePro(getTexture(tope),
                {0,0,static_cast<float>(getTexture(tope).width),static_cast<float>(getTexture(tope).height)},
                 {x ,y,64,64},
                  {32,32},rot*180/M_PI+90,WHITE);
    }

    /*void drawProjectile(Texture2D missile, std::list<Texture2D> &fireframes, float x, float y, float offset)
    {
        DrawTexture(missile,x,y,WHITE);
        int j=0;
        for(auto i=fireframes.begin(); i!=fireframes.end();++i)
        {
            if(j==currentframe)
            {
                DrawTexture(*i,x,y-offset,WHITE);
            }
            j++;
        }
        if(j<currentframe)
        {
            DrawTexture(*fireframes.begin(),x,y-offset,WHITE);
            currentframe=0;
        }
        currentframe++;
        }
    */
    /**
 *  Función dedicada a dibujar un proyectil
 *  Se le deben pasar el path a la textura, las coordenadas x e y, y la rotacion del misil.
 */
    void drawProjectile(std::string missile, float x, float y, float rot) {
        DrawTexturePro(getTexture(missile),
                       {0,0,static_cast<float>(getTexture(missile).width),static_cast<float>(getTexture(missile).height)},
                       {x ,y,64,64},
                       {32,32},rot*180/M_PI+90,WHITE);}
};

#endif //RAYLIBTEMPLATE_RENDERING_H
