#include "Object.h"

#include "raylib.h"
#include "Core/Math/SpaceConvert.h"
#include "Core/Math/Vector2.h"

#include <cmath>
#include <iostream>

Object::Object(const Texture2D &sprite)
: sprite(sprite)
{}

void Object::Move(const Vec2F& translation) {
    this->position += translation;
}

void Object::Rotate(const float rotation) {
    this->rotation += rotation;
}

void Object::Scale(const float scaleFactor) {
    this->scale *= scaleFactor;
}

Spaceship::Spaceship(const Texture2D &sprite)
: Object(sprite) {}

void Spaceship::Draw() {
    const Vec2I spriteSize = {sprite.width, sprite.height};
    const Vec2F screenSize = Vec2F(scale * SpaceConvert::PixelsPerUnit);
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
        screenSize.x,
        screenSize.y
    };

    DrawTexturePro(
        sprite,
        origin,
        destination,
        (screenSize / 2).ToRaylibVector(),
        rotation,
        WHITE
    );
}

void Spaceship::Update() {
    rotation = atan2(
        SpaceConvert::WorldToScreenPoint(position).ConvertToType<float>().y - GetMousePosition().y,
        SpaceConvert::WorldToScreenPoint(position).ConvertToType<float>().x - GetMousePosition().x
    ) * RAD2DEG - 90.0f;

    Vec2F input = {
        static_cast<float>(IsKeyDown(KEY_D) - IsKeyDown(KEY_A)),
        static_cast<float>(IsKeyDown(KEY_W) - IsKeyDown(KEY_S))
    };

    input.Normalize();

    Move(input.ConvertToType<float>() * GetFrameTime() * 10.0f);
}