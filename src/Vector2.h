#pragma once

#include <cmath>
#include <ostream>
#include "raylib.h"

template <typename T>
struct Vec2 {
    T x = 0, y = 0;

    Vec2() : x(0), y(0) {}
    Vec2(T x, T y) : x(x), y(y) {}
    Vec2(const Vec2& other) {
        this->x = other.x;
        this->y = other.y;
    }

    Vec2& operator=(const Vec2& other) = default;

    Vec2(Vec2&& other) noexcept {
        this->x = std::move(other.x);
        this->y = std::move(other.y);
        other.~Vec2();
        return *this;
    }

    Vec2& operator=(Vec2&& other)  noexcept {
        this->x = std::move(other.x);
        this->y = std::move(other.y);
        other.~Vec2();
        return *this;
    };

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
        return Vector2(static_cast<float>(x), static_cast<float>(y));
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

    Vec2& operator+=(const Vec2& other) {
        x += other.x; y += other.y;
        return *this;
    }

    Vec2& operator-=(const Vec2& other) {
        x -= other.x; y -= other.y;
        return *this;
    }

    Vec2& operator*=(const Vec2& other) {
        x *= other.x; y *= other.y;
        return *this;
    }

    Vec2& operator/=(const Vec2& other) {
        x /= other.x; y /= other.y;
        return *this;
    }

    Vec2& operator*=(const T other) {
        x *= other; y *= other;
        return *this;
    }

    Vec2& operator/=(const T other) {
        x /= other; y /= other;
        return *this;
    }

#pragma endregion Unary Arithmetic

#pragma region Binary Arithmetic
    Vec2 operator+(const Vec2& other) const {
        return Vec2(x + other.x, y + other.y);
    }

    Vec2 operator-(const Vec2& other) const {
        return Vec2(x - other.x, y - other.y);
    }

    Vec2 operator*(const Vec2& other) const {
        return Vec2(x * other.x, y * other.y);
    }

    Vec2 operator/(const Vec2& other) const {
        return Vec2(x / other.x, y / other.y);
    }

    Vec2 operator*(const T other) const {
        return Vec2(x * other, y * other);
    }

    Vec2 operator/(const T other) const {
        return Vec2(x / other, y / other);
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