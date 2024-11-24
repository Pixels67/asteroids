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

        const Vec2F worldPoint = {
            static_cast<float>(centeredScreenPoint.x * PixelsPerUnit),
            static_cast<float>(centeredScreenPoint.y * PixelsPerUnit)
        };

        return worldPoint;
    }

    Vec2I WorldToCenteredScreenPoint(const Vec2F worldPoint, const Vec2I size) {
        const Vec2I centerOffset = -size * static_cast<int>(PixelsPerUnit) / 2;
        const Vec2I screenPoint = WorldToScreenPoint(worldPoint) + centerOffset;

        return screenPoint;
    }

    Vec2F ScreenToCenteredWorldPoint(const Vec2I screenPoint, const Vec2F size) {
        const Vec2F decenterOffset = size * static_cast<float>(PixelsPerUnit) / 2;
        const Vec2F worldPoint = ScreenToWorldPoint(screenPoint) + decenterOffset;

        return worldPoint;
    }
}
