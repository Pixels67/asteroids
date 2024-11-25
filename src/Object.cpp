#include "Object.h"

#include "raylib.h"
#include "SpaceConvert.h"
#include "Vector2.h"

Object::Object(const Texture2D &sprite)
: sprite(sprite)
{}

void Object::Move(const Vec2F translation) {
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
    const Vec2F objectSize = {spriteSize.ConvertToType<float>() * scale * SpaceConvert::PixelsPerUnit};
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
        objectSize.x,
        objectSize.y
    };

    DrawTexturePro(
        sprite,
        origin,
        destination,
        (objectSize / 2).ToRaylibVector(),
        rotation,
        WHITE
    );
}
