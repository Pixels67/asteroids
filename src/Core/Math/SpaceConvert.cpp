#include "SpaceConvert.h"

#include "Core/Math/Vector2.h"

namespace SpaceConvert {
    Vec2I WorldToScreenPoint(const Vec2F& worldPoint) {
        const Vec2I screenCenter = {GetScreenWidth() / 2, GetScreenHeight() / 2};

        const Vec2I scaledWorldPoint = {
            static_cast<int>(+worldPoint.x * PixelsPerUnit),
            static_cast<int>(-worldPoint.y * PixelsPerUnit)
        };

        const Vec2I screenPoint = screenCenter + scaledWorldPoint;
        return screenPoint;
    }

    Vec2F ScreenToWorldPoint(const Vec2I& screenPoint) {
        const Vec2I screenCenter = {GetScreenWidth() / 2, GetScreenHeight() / 2};

        const Vec2I centeredScreenPoint = {
            +screenPoint.x - screenCenter.x,
            -screenPoint.y + screenCenter.y
        };

        const Vec2F worldPoint = centeredScreenPoint.ConvertToType<float>() * PixelsPerUnit;
        return worldPoint;
    }
}
