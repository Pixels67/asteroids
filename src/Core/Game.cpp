#include "Game.h"

#include "raylib.h"

constexpr float PROJECTILE_RADIUS = 15.0f;

Game::Game(const Window& window) {
    SetConfigFlags(FLAG_VSYNC_HINT);

    InitWindow(
        static_cast<int>(window.width),
        static_cast<int>(window.height),
        window.title.c_str()
    );

    InitAudioDevice();

    spaceship = Spaceship("res/spaceship.png");
}

Game::~Game() {
    CloseAudioDevice();
    CloseWindow();
}

void Game::Update(const float deltaTime) {
    Tick(deltaTime);
    BeginDrawing();
    Draw();
    EndDrawing();
}

void Game::Tick(const float deltaTime) {
    spaceship.Tick(deltaTime);

    for (int i = 0; i < m_projectiles.size(); i++) {
        m_projectiles[i].Tick(deltaTime);
        if (m_projectiles[i].position.Magnitude() > PROJECTILE_RADIUS) {
            m_projectiles.erase(m_projectiles.begin() + i);
        }
    }

    if (IsMouseButtonPressed(0)) {
        CreateProjectile(spaceship.position, -spaceship.rotation + 90.0f);
    }
}

void Game::Draw() const {
    ClearBackground(BLACK);

    spaceship.Draw();

    for (const auto &projectile : m_projectiles) {
        projectile.Draw();
    }

    DrawFPS(0.0f, 0.0f);
}

bool Game::IsRunning() const {
    return !WindowShouldClose();
}

void Game::CreateProjectile(const Vec2F& position, float angleDegrees) {
    m_projectiles.emplace_back("res/projectile.png", position, angleDegrees);
}
