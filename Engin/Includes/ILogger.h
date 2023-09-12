#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <Windows.h>
#include <string.h>

namespace project {

	class IILogger {
	public:
		virtual ~IILogger() = default;
		virtual void WriteLogText(std::string logtext) = 0;
	};
}
