#include "raylib.h"

int main() {
    InitWindow(800, 600, "Asteroids");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
}