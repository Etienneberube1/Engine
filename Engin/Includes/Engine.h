#pragma once
#include <string>
#include "IInput.h"
#include "Ilogger.h"

namespace project {
	class Engine final {
	public:
	public:
		bool Init(const char* name, int w, int h);
		void Start(void);
		IInput& Input() const { return* m_Input; };
	private:
		void ProcessInput(void);
		void Update(float dt);
		void Render(void);
		void Shutdown(void);

	private:
		IInput* m_Input;
		IILogger* m_Logger;
		bool m_IsInit = false;
	};
}