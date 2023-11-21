#pragma once

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
    };

}
