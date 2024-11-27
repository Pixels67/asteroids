#pragma once

#include <vector>

#include "Object.h"
#include "Core/Math/Vector2.h"

struct Window {
    size_t width, height;
    std::string title;
};

class Game {
public:
    explicit Game(const Window& window);
    ~Game();

    void Update(float deltaTime);
    void Tick(float deltaTime);
    void Draw() const;
    [[nodiscard]] bool IsRunning() const;

    void CreateProjectile(const Vec2F& position = Vec2F(0.0f, 0.0f), float angleDegrees = 0.0f);
private:
    Spaceship spaceship;
    std::vector<Projectile> m_projectiles;
};
