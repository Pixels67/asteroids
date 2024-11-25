#pragma once

#include "Core/Math/Vector2.h"

namespace SpaceConvert {
    inline float PixelsPerUnit = 50;

    Vec2I WorldToScreenPoint(const Vec2F& worldPoint);
    Vec2F ScreenToWorldPoint(const Vec2I& screenPoint);
};