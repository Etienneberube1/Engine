#pragma once
#include <math.h>

namespace project {

    class Vector3 {
    public:
        float x, y, z;

        Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f) : x(x), y(y), z(z) {}

        Vector3 operator + (const Vector3& other) const {
            return Vector3(x + other.x, y + other.y, z + other.z);
        }

        Vector3 operator - (const Vector3& other) const {
            return Vector3(x - other.x, y - other.y, z - other.z);
        }

        Vector3 operator * (float scalar) const {
            return Vector3(x * scalar, y * scalar, z * scalar);
        }

        Vector3 operator / (float scalar) const {
            return Vector3(x / scalar, y / scalar, z / scalar);
        }

        Vector3& operator += (const Vector3& other) {
            x += other.x;
            y += other.y;
            z += other.z;
            return *this;
        }

        void Vector3::Normalize() {
            float length = sqrt(x * x + y * y + z * z);
            if (length != 0) {
                x /= length;
                y /= length;
                z /= length;
            }
        }

        Vector3 Vector3::Normalized() const {
            Vector3 temp = *this;
            temp.Normalize();
            return temp;
        }

        static float Distance(const Vector3& a, const Vector3& b) {
            float dx = a.x - b.x;
            float dy = a.y - b.y;
            float dz = a.z - b.z;
            return sqrt(dx * dx + dy * dy + dz * dz);
        }

        float Length() const {
            return sqrt(x * x + y * y + z * z);
        }
    };

}
