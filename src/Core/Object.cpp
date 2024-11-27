#include "Object.h"

#include "raylib.h"
#include "Core/Math/SpaceConvert.h"
#include "Core/Math/Vector2.h"

constexpr float SPACESHIP_SPEED = 10.0f;
constexpr float PROJECTILE_SPEED = 10.0f;

Object::Object(const std::string &spritePath, Vec2F position, const float rotation, const float scale)
: position(std::move(position)), rotation(rotation), scale(scale), sprite(LoadTexture(spritePath.c_str())) {}

void Object::Draw() const {
    const Vec2I spriteSize = {sprite.width, sprite.height};
    const Vec2F objectScreenSize = spriteSize.ConvertToType<float>() * scale;
    const Vec2F screenPoint = SpaceConvert::WorldToScreenPoint(position).ConvertToType<float>();

    const Rectangle origin = {
        0,
        0,
        spriteSize.ConvertToType<float>().x,
        spriteSize.ConvertToType<float>().y
    };

    const Rectangle destination = {
        screenPoint.x,
        screenPoint.y,
        objectScreenSize.x,
        objectScreenSize.y
    };

    DrawTexturePro(
        sprite,
        origin,
        destination,
        (objectScreenSize / 2).ToRaylibVector(),
        rotation,
        WHITE
    );
}


void Object::Move(const Vec2F& translation) {
    this->position += translation;
}

void Object::Rotate(const float rotation) {
    this->rotation += rotation;
}

void Object::Scale(const float scaleFactor) {
    this->scale *= scaleFactor;
}

Spaceship::Spaceship() : Object() {
}

Spaceship::Spaceship(const std::string &spritePath)
: Object(spritePath) {}

void Spaceship::Tick(const float deltaTime) {
    rotation = atan2(
        SpaceConvert::WorldToScreenPoint(position).ConvertToType<float>().y - GetMousePosition().y,
        SpaceConvert::WorldToScreenPoint(position).ConvertToType<float>().x - GetMousePosition().x
    ) * RAD2DEG - 90.0f;

    Vec2F input = {
        static_cast<float>(IsKeyDown(KEY_D) - IsKeyDown(KEY_A)),
        static_cast<float>(IsKeyDown(KEY_W) - IsKeyDown(KEY_S))
    };

    input.Normalize();

    Move(input.ConvertToType<float>() * deltaTime * SPACESHIP_SPEED);

    if (position.x > static_cast<float>(GetScreenWidth()) / 2 / SpaceConvert::PixelsPerUnit) {
        position.x = static_cast<float>(GetScreenWidth()) / 2 / SpaceConvert::PixelsPerUnit;
    }
    if (position.x < -static_cast<float>(GetScreenWidth()) / 2 / SpaceConvert::PixelsPerUnit) {
        position.x = -static_cast<float>(GetScreenWidth()) / 2 / SpaceConvert::PixelsPerUnit;
    }
    if (position.y > static_cast<float>(GetScreenHeight()) / 2 / SpaceConvert::PixelsPerUnit) {
        position.y = static_cast<float>(GetScreenHeight()) / 2 / SpaceConvert::PixelsPerUnit;
    }
    if (position.y < -static_cast<float>(GetScreenHeight()) / 2 / SpaceConvert::PixelsPerUnit) {
        position.y =- static_cast<float>(GetScreenHeight()) / 2 / SpaceConvert::PixelsPerUnit;
    }
}

Projectile::Projectile(const std::string &spritePath, const Vec2F& position, float angleDegrees)
    : Object(spritePath, position, 0.0f, 1.0f) {
    direction = {
        static_cast<float>(cos(angleDegrees * DEG2RAD)),
        static_cast<float>(sin(angleDegrees * DEG2RAD))
    };
}

void Projectile::Tick(const float deltaTime) {
    Move(direction * deltaTime * PROJECTILE_SPEED);
}