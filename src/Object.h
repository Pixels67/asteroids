#pragma once

#include "raylib.h"
#include "Vector2.h"

class Object {
public:
    Vec2F position{};
    float rotation{};
    float scale{1};
    Texture2D sprite{};

    explicit Object(const Texture2D &sprite);
    virtual ~Object() = default;

    virtual void Draw() = 0;
    virtual void Move(Vec2F translation);
    virtual void Rotate(float rotation);
};

class Spaceship final : public Object {
public:
    explicit Spaceship(const Texture2D &sprite);

    void Draw() override;
};