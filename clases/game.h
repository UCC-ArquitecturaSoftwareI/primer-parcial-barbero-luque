//
// Created by Agustin on 1/6/2020.
//

#ifndef RAYLIBTEMPLATE_GAME_H
#define RAYLIBTEMPLATE_GAME_H


class Game{
public:
    static Game& GetInstance ();
    void Start () const;
    void Stop () const;
private:
    Game();
};

#endif //RAYLIBTEMPLATE_GAME_H
