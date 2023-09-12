#pragma once 
#include "LogConsole.h"

namespace project {

	LogConsole::LogConsole() {
		AllocConsole();
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		int _r = freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);

	}

	LogConsole::~LogConsole() {
		FreeConsole();
	}

	void LogConsole::WriteLogText(std::string logtext) {
		SetConsoleTextAttribute(hConsole, 2);
		std::cout << logtext << std::endl;
	}

}
