#include "raylib.h"
#include "Core/Object.h"

int main() {
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(800, 600, "Asteroids");

    Spaceship spaceship("res/spaceship.png");
    Projectile bullet("res/projectile.png", 0);

    while (!WindowShouldClose()) {
        spaceship.Update();
        bullet.Update();

        BeginDrawing();

        ClearBackground(BLACK);
        bullet.Draw();
        spaceship.Draw();
        DrawFPS(0, 0);

        EndDrawing();
    }

    CloseWindow();
}
