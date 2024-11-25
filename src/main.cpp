#include "raylib.h"
#include "Object.h"

int main() {
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(800, 600, "Asteroids");

    const Texture2D sprite = LoadTexture("./res/spaceship.png");
    Spaceship spaceship(sprite);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        spaceship.Rotate(2.0f);
        spaceship.Draw();
        DrawFPS(0, 0);
        EndDrawing();
    }

    CloseWindow();
}
