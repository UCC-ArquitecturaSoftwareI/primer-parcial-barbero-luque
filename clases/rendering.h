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

class rendering {
private:
    int currentframe = 0;
    std::unordered_map<std::string, Texture2D> textMap;

    Texture2D &getTexture(std::string s)  //Flyweight para pasar las texturas dentro del Renderer
    {
        auto myText=textMap.find(s);
        if (myText==textMap.end())
        {
            char c[s.size()+1];
            s.copy(c,s.size()+1);
            textMap.emplace(s,LoadTexture(c));
        }

        return textMap[s];

    }
public:
    //TODO: PASAR TODO A DRAWTEXTUREEXTENDED
    void drawEnemy(Texture2D a, float x, float y) {
        DrawTexture(a, x - a.width / 2, y - a.height / 2, WHITE);
    }

    void drawPhantomTextureTower(std::string base, std::string tope, float x, float y) {
        DrawTexture(getTexture(base), x - getTexture(base).width / 2, y - getTexture(base).height / 2, GREEN);
        DrawTexture(getTexture(tope), x - getTexture(tope).width / 2, y - getTexture(tope).height / 2, GREEN);
    }

    void drawPhantomTextureError(std::string base, std::string tope, float x, float y) {
        DrawTexture(getTexture(base), x - getTexture(base).width / 2, y - getTexture(base).height / 2, RED);
        DrawTexture(getTexture(tope), x - getTexture(tope).width / 2, y - getTexture(tope).height / 2, RED);
    }

    void drawTower(std::string base, std::string tope, float x, float y, float rot) {
        DrawTexture(getTexture(base), x - getTexture(base).width / 2, y - getTexture(base).height / 2, WHITE);
        DrawTextureEx(getTexture(tope), {x - getTexture(tope).width / 2, y - getTexture(tope).height / 2},rot*360,1, WHITE);
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
        } TODO: PULIR Y LOGRAR QUE ANDE.
    */

    void drawProjectile(std::string missile, float x, float y, float rot) {
        DrawTextureEx(getTexture(missile), {x, y},rot*360,1, WHITE);
    }
};

#endif //RAYLIBTEMPLATE_RENDERING_H
