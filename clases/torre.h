//
// Created by Francisco on 21/4/2020.
//

#ifndef PROYECTO_TORRE_H
#define PROYECTO_TORRE_H

#include <string>
#include "enemies.h"

class torre{
protected:
    int cost;
   std::string name;
public:
    torre(int a, std::string b);

    int getcost(){
        return cost;
    };

    std::string getname()
    {
        return name;
    };

    void fireProj(enemies);
};
#endif //PROYECTO_TORRE_H
