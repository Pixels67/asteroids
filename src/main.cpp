#include "raylib.h"
#include "Object.h"

int main() {
    InitWindow(800, 600, "Asteroids");

    const Texture2D sprite = LoadTexture("../res/spaceship.png");
    Spaceship spaceship(sprite);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        spaceship.Draw();
        EndDrawing();
    }

    CloseWindow();
}
