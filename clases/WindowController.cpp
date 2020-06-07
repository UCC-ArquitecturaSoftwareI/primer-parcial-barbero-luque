//
// Created by Francisco on 21/4/2020.
//

#include "WindowController.h"




    void windowcontroller::start(){
        InitWindow(screenWidth, screenHeight, "Tower Defense");
        InitGameplayScreen();
        SetTargetFPS(60);

    }

    /**
 *  Función dedicada a dibujar cada frame. Acá adentro se debe poner la logica necesaria para representar un nuevo frame
 *  del juego.
 */
    void windowcontroller::UpdateDrawFrame() {

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
