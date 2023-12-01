#pragma once
#include <string>
#include <map>
#include <vector>
#include <Component.h>
#include <IUpdatable.h>
#include <IDrawable.h>
#include <RectF.h>
#include "Vector3.h"

namespace project {

    // Class representing an entity in the game world.
    class Entity final
    {
    public:
        // Destructor.
        virtual ~Entity() = default;

        // Constructor with entity name.
        Entity(const std::string& name);

        // Lifecycle methods for the entity.
        virtual void Start();
        virtual void Update(float dt);
        virtual void Draw();
        virtual void Destroy();

        // Gets the name of the entity.
        std::string& GetName() { return m_name; }

        // Sets the position of the entity.
        void SetPosition(const Vector3& position) {
            m_x = position.x;
            m_y = position.y;
        }

        // Sets the size of the entity.
        void SetSize(float w, float h) {
            m_width = w;
            m_height = h;
        }

        // Sets the rotation angle of the entity.
        void SetRotation(double angle) {
            m_angle = angle;
        }

        // Translates the entity by a given delta.
        void Translate(float dx, float dy) {
            m_x += dx;
            m_y += dy;
        }

        // Sets the x-coordinate of the entity.
        void SetX(float x) {
            m_x = x;
        }

        // Sets the y-coordinate of the entity.
        void SetY(float y) {
            m_y = y;
        }

        // Scales the entity by a given factor.
        void Scale(float dw, float dh) {
            m_width *= dw;
            m_width *= dh;
        }

        // Rotates the entity by a given angle.
        void Rotate(double angle) {
            m_angle += angle;
        }

        // Gets the position of the entity.
        void GetPosition(float* x, float* y) {
            *x = m_x;
            *y = m_y;
        }

        // Returns the position as a Vector3.
        Vector3 GetPosition() const {
            return Vector3(m_x, m_y, 0.0f);
        }

        // Gets the x and y coordinates.
        float GetX() const { return m_x; }
        float GetY() const { return m_y; }

        // Gets the width and height of the entity.
        void GetSize(float* w, float* h) {
            *w = m_width;
            *h = m_height;
        }

        float GetWidth() const { return m_width; }
        float GetHeight() const { return m_height; }

        // Gets the rotation angle of the entity.
        double GetRotation() const { return m_angle; }

        // Gets the RectF representing the entity's bounds.
        void GetRect(RectF* rect) {
            *rect = RectF{ m_x, m_y, m_width, m_height };
        }

        RectF GetRect() {
            return RectF{ m_x, m_y, m_width, m_height };
        }

        // Template methods for adding and getting components.
        template <typename T>
        T* AddComponent()
        {
            T* component = new T(this);
            const type_info* type = &typeid(*component);
            if (m_componentByType.count(type) == 0)
            {
                m_componentByType.emplace(type, component);

                auto _updatable = dynamic_cast<IUpdatable*>(component);
                if (_updatable != nullptr)
                {
                    m_updatableComponents.emplace_back(_updatable);
                }

                auto _drawable = dynamic_cast<IDrawable*>(component);
                if (_drawable != nullptr)
                {
                    m_drawableComponents.emplace_back(_drawable);
                }

                return component;
            }

            return nullptr;
        }

        template <typename T>
        T* GetComponent()
        {
            const type_info* type = &typeid(T);
            if (m_componentByType.count(type) > 0)
            {
                return static_cast<T*>(m_componentByType[type]);
            }

            return nullptr;
        }

    protected:
        std::string m_name;

        std::map<const type_info*, Component*> m_componentByType;
        std::vector<IUpdatable*> m_updatableComponents;
        std::vector<IDrawable*> m_drawableComponents;

        float m_x = 0.0f;
        float m_y = 0.0f;
        double m_angle = 0.0;
        float m_width = 1.0f;
        float m_height = 1.0f;
    };
}
