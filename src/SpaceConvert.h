#pragma once

#include "Vector2.h"

namespace SpaceConvert {
    inline size_t PixelsPerUnit = 2;

    Vec2I WorldToScreenPoint(Vec2F worldPoint);
    Vec2F ScreenToWorldPoint(Vec2I screenPoint);

    Vec2I WorldToCenteredScreenPoint(Vec2F worldPoint, Vec2I size);
    Vec2F ScreenToCenteredWorldPoint(Vec2I screenPoint, Vec2F size);
};