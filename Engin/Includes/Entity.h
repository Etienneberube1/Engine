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

	class Entity final
	{
	public:
		virtual ~Entity() = default;
		Entity(const std::string& name);

		virtual void Start();
		virtual void Update(float dt);
		virtual void Draw();
		virtual void Destroy();

		std::string& GetName() { return m_Name; }

		void SetPosition(const Vector3& position) {
			m_X = position.x;
			m_Y = position.y;
		}

		void SetSize(float w, float h)
		{
			m_Width = w;
			m_Height = h;
		}

		void SetRotation(double angle)
		{
			m_Angle = angle;
		}

		void Translate(float dx, float dy)
		{
			m_X += dx;
			m_Y += dy;
		}

		void SetY(float y)
		{
			m_Y = y;
		}
		void SetX(float x)
		{
			m_X = x;
		}
		
		void Scale(float dw, float dh)
		{
			m_Width *= dw;
			m_Width *= dh;
		}

		void Rotate(double angle)
		{
			m_Angle += angle;
		}

		void GetPosition(float* x, float* y)
		{
			*x = m_X;
			*y = m_Y;
		}

		Vector3 GetPosition() const {
			return Vector3(m_X, m_Y, 0.0f);
		}

		float GetX() const { return m_X; }
		float GetY() const { return m_Y; }

		void GetSize(float* w, float* h)
		{
			*w = m_Width;
			*h = m_Height;
		}

		float GetWidth() const { return m_Width; }
		float GetHeight() const { return m_Height; }

		double GetRotation() const { return m_Angle; }

		void GetRect(RectF* rect)
		{
			*rect = {
				m_X, m_Y,
				m_Width, m_Height
			};
		}



		RectF GetRect() 
		{
			RectF tmp = {
						m_X, m_Y,
				m_Width, m_Height
				
			};
			return tmp;
		}


		template <typename T>
		T* AddComponent()
		{
			T* component = new T(this);
			const type_info* type = &typeid(*component);
			if (m_ComponentByType.count(type) == 0)
			{
				m_ComponentByType.emplace(type, component);

				auto _updatable = dynamic_cast<IUpdatable*>(component);
				if (_updatable != nullptr)
				{
					m_UpdatableComponents.emplace_back(_updatable);
				}

				auto _drawable = dynamic_cast<IDrawable*>(component);
				if (_drawable != nullptr)
				{
					m_DrawableComponents.emplace_back(_drawable);
				}

				return component;
			}

			return nullptr;
		}

		template <typename T>
		T* GetComponent()
		{
			const type_info* type = &typeid(T);
			if (m_ComponentByType.count(type) > 0)
			{
				return static_cast<T*>(m_ComponentByType[type]);
			}

			return nullptr;
		}

	protected:
		std::string m_Name;

		std::map<const type_info*, Component*> m_ComponentByType;
		std::vector<IUpdatable*> m_UpdatableComponents;
		std::vector<IDrawable*> m_DrawableComponents;

		float m_X = 0.0f;
		float m_Y = 0.0f;
		double m_Angle = 0.0;
		float m_Width = 1.0f;
		float m_Height = 1.0f;
	};
}