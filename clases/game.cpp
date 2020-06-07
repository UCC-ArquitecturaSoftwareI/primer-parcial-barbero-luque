//
// Created by Agustin on 1/6/2020.
//

#include "game.h"

Game::Game (){

}

Game& Game::GetInstance (){
    static Game instance;
    return instance;
}

void Game::Start () const{

}

void Game::Stop () const{

}
