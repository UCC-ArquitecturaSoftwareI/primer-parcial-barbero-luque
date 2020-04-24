//
// Created by Francisco on 21/4/2020.
//

#include <raylib.h>

#include "gameplayScreen.cpp"


const int screenWidth = 800;
const int screenHeight = 450;


class windowcontroller{
public:
    void start(){
        InitWindow(screenWidth, screenHeight, "Tower Defense");
        InitGameplayScreen();
        SetTargetFPS(60);

    }

    /**
 *  Función dedicada a dibujar cada frame. Acá adentro se debe poner la logica necesaria para representar un nuevo frame
 *  del juego.
 */
    static void UpdateDrawFrame(void) {

        // siempre hay que reproducir la musica que esta actualmente
        //UpdateMusicStream(music);

        UpdateGameplayScreen();


        // Comienzo a dibujar
        BeginDrawing();

        ClearBackground(RAYWHITE); // Limpio la pantalla con blanco

        DrawGameplayScreen();

        // Finalizo el dibujado
        EndDrawing();
    }
};