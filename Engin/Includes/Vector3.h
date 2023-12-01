#pragma once
#include <math.h>

namespace project {

    // Represents a three-dimensional vector.
    class Vector3 {
    public:
        float x, y, z;

        // Constructor.
        Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f) : x(x), y(y), z(z) {}

        // Operator overloads for vector arithmetic.
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

        // Normalizes the vector.
        void Normalize() {
            float length = static_cast<float>(sqrt(x * x + y * y + z * z));
            if (length != 0) {
                x /= length;
                y /= length;
                z /= length;
            }
        }

        // Returns a normalized copy of the vector.
        Vector3 Normalized() const {
            Vector3 temp = *this;
            temp.Normalize();
            return temp;
        }

        // Static method for calculating the distance between two vectors.
        static float Distance(const Vector3& a, const Vector3& b) {
            float dx = a.x - b.x;
            float dy = a.y - b.y;
            float dz = a.z - b.z;
            return static_cast<float>(sqrt(dx * dx + dy * dy + dz * dz));
        }

        // Calculates the length of the vector.
        float Length() const {
            return static_cast<float>(sqrt(x * x + y * y + z * z));
        }

        // Unary minus operator.
        Vector3 operator - () const {
            return Vector3(-x, -y, -z);
        }
    };

}
