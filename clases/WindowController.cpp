//
// Created by Francisco on 21/4/2020.
//

#include <raylib.h>

#include "clases/Nave.h"
#include "Nave.h"

const int screenWidth = 800;
const int screenHeight = 450;

static void UpdateDrawFrame(void);          // Función dedicada a operar cada frame


Nave *player;

class windowcontroller{
    void start(){
        InitWindow(screenWidth, screenHeight, "raylib template - advance game");
        player = new Nave("resources/ship.png", Vector2{screenWidth / 2, screenHeight / 2});
    }

    /**
 *  Función dedicada a dibujar cada frame. Acá adentro se debe poner la logica necesaria para representar un nuevo frame
 *  del juego.
 */
    static void UpdateDrawFrame(void) {

        // siempre hay que reproducir la musica que esta actualmente
        UpdateMusicStream(music);

        // Verifico Entradas de eventos.
        if (IsKeyDown(KEY_RIGHT)) player->move_x(2.0f);
        if (IsKeyDown(KEY_LEFT)) player->move_x(-2.0f);
        if (IsKeyDown(KEY_UP)) player->move_y(-2.0f);
        if (IsKeyDown(KEY_DOWN)) player->move_y(2.0f);


        // Comienzo a dibujar
        BeginDrawing();

        ClearBackground(RAYWHITE); // Limpio la pantalla con blanco

        // Dibujo todos los elementos del juego.
        player->draw();
        DrawText("Inicio", 20, 20, 40, LIGHTGRAY);

        // Finalizo el dibujado
        EndDrawing();
    }
};