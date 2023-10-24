#pragma once
#include "IGraphics.h"
#include "IAudio.h"
#include "IInput.h"
#include "ILogger.h"
#include "Entity.h"

struct Entity;

namespace project {

	class Component
	{
	private:
		Component() = default;
	public:
		Component(Entity* entity);
		virtual ~Component() = default;
		virtual void Start() {}
		virtual void Destroy() {}

		virtual IAudio* Audio() const;
		virtual IInput* Input() const;
		virtual IGraphics* Graphics() const;
		virtual IILogger* Logger() const;

	protected:
		Entity* m_Entity = nullptr;

	};
}




