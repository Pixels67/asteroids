#pragma once

#include "raylib.h"
#include "Core/Math/Vector2.h"

class Object {
public:
    Vec2F position{};
    float rotation{};
    float scale{1};
    Texture2D sprite{};

    explicit Object(const Texture2D &sprite);
    virtual ~Object() = default;

    virtual void Draw() = 0;
    virtual void Move(const Vec2F& translation);
    virtual void Rotate(float rotation);
    virtual void Scale(float scaleFactor);
};

class Spaceship final : public Object {
public:
    explicit Spaceship(const Texture2D &sprite);
    Spaceship(const Spaceship &other) = delete;
    Spaceship& operator=(const Spaceship &other) = delete;
    Spaceship(Spaceship &&other) = delete;
    Spaceship& operator=(Spaceship &&other) = delete;

    void Draw() override;
    void Update();
};