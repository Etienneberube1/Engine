#pragma once 
#include "ILogger.h"

namespace project {

	class Logs : public IILogger {
	public:
		Logs();
		~Logs();
		virtual void WriteLogText(std::string logtext) override;
	private:
		std::ofstream LogFile;
	};
}
