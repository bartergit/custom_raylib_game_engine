#pragma once

namespace vec {
    template<typename T>
    struct Vector2 {
        T x;
        T y;

        Vector2(T x, T y) : x(x), y(y) {}

        Vector2() {
            x = 0;
            y = 0;
        }

        Vector2 operator+(Vector2 other) {
            return Vector2(x + other.x, y + other.y);
        }

        Vector2 &operator+=(Vector2 other) {
            this->x += other.x;
            this->y += other.y;
            return *this;
        }

        Vector2 operator-(Vector2 other) {
            return Vector2(x - other.x, y - other.y);
        }

        Vector2 operator-() {
            return Vector2(-x, -y);
        }

        Vector2 operator*(T t) {
            return Vector2(t * x, t * y);
        }


        Vector2 operator/(T t) {
            return Vector2(x / t, y / t);
        }

        Vector2 squared_magnitude() {
            return x * x + y * y;
        }

        Vector2 magnitude() {
            return sqrt(squared_magnitude());
        }

        Vector2 scalar_multiply(Vector2 other) {
            return Vector2(other.x * x + other.y * y);
        }

        T cross_product(Vector2 other) {
            return x * other.y - y * other.x;
        }

        std::string str() {
            std::stringstream ss;
            ss << "Vector3(" << x << ", " << y << ")";
            return ss.str();
        }

        bool is_zero() {
            return x == 0 and y == 0;
        }
    };
}
