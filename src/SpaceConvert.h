#pragma once

#include "Vector2.h"

namespace SpaceConvert {
    inline float PixelsPerUnit = 2;

    Vec2I WorldToScreenPoint(Vec2F worldPoint);
    Vec2F ScreenToWorldPoint(Vec2I screenPoint);
};