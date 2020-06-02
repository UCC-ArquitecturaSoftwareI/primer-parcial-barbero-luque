#include <raylib.h>
#include "clases/WindowController.h"
#if defined(PLATFORM_WEB) // Para crear HTML5
#include <emscripten/emscripten.h>
#endif


// Variables Globales
//Music music;
windowcontroller w;


int main() {
    // Inicialización de la ventana

    //InitAudioDevice();              // Initialize audio device

    /// Ejemplo de utilización de audio.
    //music = LoadMusicStream("resources/Cyberpunk Moonlight Sonata.mp3");

    //PlayMusicStream(music);
    w.start();

#if defined(PLATFORM_WEB)  // Para versión Web.
    emscripten_set_main_loop(w.UpdateDrawFrame, 0, 1);
#else
    SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
    // Main loop
    while (!WindowShouldClose()) {
        w.UpdateDrawFrame();
    }
#endif


    // Descargar todos los resources cargados

    //UnloadMusicStream(music);   // Descargo la musica de RAM
    CloseAudioDevice();         // Cierro el dispositivo de Audio
    CloseWindow();              // Cierro la ventana
    return 0;
}


