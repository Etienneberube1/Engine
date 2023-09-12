#pragma once 
#include "Logs.h"

namespace project {

	Logs::Logs() {
		LogFile.open("Logs.txt");
	}

	Logs::~Logs() {
		LogFile.close();
	}

	void Logs::WriteLogText(std::string logtext) {
		LogFile << logtext;
	}
	

}

