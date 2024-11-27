#pragma once

#include "raylib.h"
#include "Core/Math/Vector2.h"

class Object {
public:
    Vec2F position{};
    float rotation{};
    float scale{1};
    Texture2D sprite{};

    Object() = default;
    explicit Object(const std::string &spritePath, Vec2F position = {0, 0}, float rotation = 0, float scale = 1);
    virtual ~Object() = default;

    virtual void Tick(float deltaTime) = 0;
    virtual void Draw() const;
    virtual void Move(const Vec2F& translation);
    virtual void Rotate(float rotation);
    virtual void Scale(float scaleFactor);
};

class Spaceship final : public Object {

public:
    Spaceship();
    explicit Spaceship(const std::string &spritePath);
    Spaceship(const Spaceship &other) = delete;
    Spaceship& operator=(const Spaceship &other) = delete;
    Spaceship(Spaceship &&other) = default;
    Spaceship& operator=(Spaceship &&other) = default;

    void Tick(float deltaTime) override;
};

class Projectile final : public Object {
public:
    explicit Projectile(const std::string &spritePath, const Vec2F& position = {0.0f, 0.0f}, float angleDegrees = 0.0f);
    Projectile(const Projectile &other) = delete;
    Projectile& operator=(const Projectile &other) = delete;
    Projectile(Projectile &&other) = default;
    Projectile& operator=(Projectile &&other) = default;

    void Tick(float deltaTime) override;
private:
    Vec2F direction{};
};