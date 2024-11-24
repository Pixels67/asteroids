#include "Object.h"

#include "raylib.h"
#include "SpaceConvert.h"
#include "Vector2.h"

Object::Object(const Texture2D &sprite)
: sprite(sprite)
{}

void Object::Move(const Vec2F translation) {
    position += translation;
}

void Object::Rotate(const float rotation) {
    this->rotation += rotation;
}

Spaceship::Spaceship(const Texture2D &sprite)
: Object(sprite) {}

void Spaceship::Draw() {
    const Vec2I spriteSize = {sprite.width, sprite.height};
    const Vec2I objectSize = {spriteSize * static_cast<int>(scale)};
    const Vec2I screenPoint = SpaceConvert::WorldToCenteredScreenPoint(position, objectSize);

    DrawTextureEx(
        sprite,
        screenPoint.ToRaylibVector(),
        rotation,
        scale * static_cast<float>(SpaceConvert::PixelsPerUnit),
        WHITE
    );
}
