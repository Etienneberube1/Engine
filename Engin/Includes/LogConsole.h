#pragma once 
#include "ILogger.h"
namespace project {

	class LogConsole : public IILogger {
	public:
		LogConsole();
		~LogConsole();
		virtual void WriteLogText(std::string logtext) override;
	private:
		HANDLE hConsole;
	};
}
