#include "SpaceConvert.h"

#include "Vector2.h"

namespace SpaceConvert {
    Vec2I WorldToScreenPoint(const Vec2F worldPoint) {
        const Vec2I screenCenter = {GetScreenWidth() / 2, GetScreenHeight() / 2};

        const Vec2I scaledWorldPoint = {
            static_cast<int>(+worldPoint.x) * static_cast<int>(PixelsPerUnit),
            static_cast<int>(-worldPoint.y) * static_cast<int>(PixelsPerUnit)
        };

        const Vec2I screenPoint = screenCenter + scaledWorldPoint;
        return screenPoint;
    }

    Vec2F ScreenToWorldPoint(const Vec2I screenPoint) {
        const Vec2I screenCenter = {GetScreenWidth() / 2, GetScreenHeight() / 2};

        const Vec2I centeredScreenPoint = {
            +screenPoint.x - screenCenter.x,
            -screenPoint.y + screenCenter.y
        };

        const Vec2F worldPoint = centeredScreenPoint.ConvertToType<float>() * PixelsPerUnit;
        return worldPoint;
    }
}
