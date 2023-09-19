#pragma once
#include <string>
#include "IInput.h"
#include "Ilogger.h"
#include "IGraphics.h"
namespace project {
	class Engine final {
	public:
		bool Init(const char* name, int w, int h);
		void Start(void);
		IInput& Input() const { return* m_Input; };
	private:
		void ProcessInput(void);
		void Update(float dt);
		void Render(void);
		void Shutdown(void);

		IGraphics* m_Graphics = nullptr;
		IInput* m_Input = nullptr;
		IILogger* m_Logger = nullptr;
		bool m_IsInit = false;
	};
}