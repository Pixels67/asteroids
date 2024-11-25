#include "raylib.h"
#include "Core/Object.h"

int main() {
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(800, 600, "Asteroids");

    const Texture2D sprite = LoadTexture("res/spaceship.png");
    Spaceship spaceship(sprite);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        spaceship.Update();
        spaceship.Draw();
        DrawFPS(0, 0);
        EndDrawing();
    }

    CloseWindow();
}
