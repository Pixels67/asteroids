#pragma once

#include "raylib.h"
#include "Core/Math/Vector2.h"

class Object {
public:
    Vec2F position{};
    float rotation{};
    float scale{1};
    Texture2D sprite{};

    explicit Object(const std::string &spritePath, const Vec2F &position = {0, 0}, float rotation = 0, float scale = 1);
    virtual ~Object() = default;

    virtual void Draw();
    virtual void Move(const Vec2F& translation);
    virtual void Rotate(float rotation);
    virtual void Scale(float scaleFactor);
};

class Spaceship final : public Object {
public:
    explicit Spaceship(const std::string &spritePath);
    Spaceship(const Spaceship &other) = delete;
    Spaceship& operator=(const Spaceship &other) = delete;
    Spaceship(Spaceship &&other) = delete;
    Spaceship& operator=(Spaceship &&other) = delete;

    void Update();
};

class Projectile final : public Object {
public:
    explicit Projectile(const std::string &spritePath, float angleDegrees);
    Projectile(const Projectile &other) = delete;
    Projectile& operator=(const Projectile &other) = delete;
    Projectile(Projectile &&other) = delete;
    Projectile& operator=(Projectile &&other) = delete;

    void Update();
private:
    Vec2F direction{};
};