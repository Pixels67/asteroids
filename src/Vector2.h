#pragma once

#include <cmath>
#include <ostream>
#include "raylib.h"

template <typename T>
struct Vec2 {
    T x = 0, y = 0;

    Vec2() : x(0), y(0) {}
    Vec2(T x, T y) : x(x), y(y) {}

#pragma region Utility Methods

    template <typename U>
    Vec2<U> ConvertToType() const {
        return {static_cast<U>(x), static_cast<U>(y)};
    }

    [[nodiscard]] float Magnitude() const {
        return sqrt(x * x + y * y);
    }

    [[nodiscard]] size_t SqrMagnitude() const {
        return x * x + y * y;
    }

    [[nodiscard]] Vec2 Normalized() const {
        return Vec2(x / Magnitude(), y / Magnitude());
    }

    [[nodiscard]] Vector2 ToRaylibVector() const {
        return Vector2(x, y);
    }

#pragma endregion Utility Methods

#pragma region Operation Overloads

#pragma region Unary Arithmetic
    Vec2 operator+() const {
        return *this;
    }

    Vec2 operator-() const {
        return Vec2(-x, -y);
    }

    Vec2& operator+=(const Vec2& rhs) {
        x += rhs.x; y += rhs.y;
        return *this;
    }

    Vec2& operator-=(const Vec2& rhs) {
        x -= rhs.x; y -= rhs.y;
        return *this;
    }

    Vec2& operator*=(const Vec2& rhs) {
        x *= rhs.x; y *= rhs.y;
        return *this;
    }

    Vec2& operator/=(const Vec2& rhs) {
        x /= rhs.x; y /= rhs.y;
        return *this;
    }

    Vec2& operator*=(const T rhs) {
        x *= rhs; y *= rhs;
        return *this;
    }

    Vec2& operator/=(const T rhs) {
        x /= rhs; y /= rhs;
        return *this;
    }

#pragma endregion Unary Arithmetic

#pragma region Binary Arithmetic
    Vec2 operator+(const Vec2& rhs) const {
        return Vec2(x + rhs.x, y + rhs.y);
    }

    Vec2 operator-(const Vec2& rhs) const {
        return Vec2(x - rhs.x, y - rhs.y);
    }

    Vec2 operator*(const Vec2& rhs) const {
        return Vec2(x * rhs.x, y * rhs.y);
    }

    Vec2 operator/(const Vec2& rhs) const {
        return Vec2(x / rhs.x, y / rhs.y);
    }

    Vec2 operator*(const T rhs) const {
        return Vec2(x * rhs, y * rhs);
    }

    Vec2 operator/(const T rhs) const {
        return Vec2(x / rhs, y / rhs);
    }

#pragma endregion Binary Arithmetic

#pragma endregion Operation Overloads
};

template <typename T>
std::ostream &operator<<(std::ostream &out, Vec2<T> vector) {
    return out << "(" << vector.x << ", " << vector.y << ")";
}

using Vec2I = Vec2<int>;
using Vec2S = Vec2<size_t>;
using Vec2F = Vec2<float>;