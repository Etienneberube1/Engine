#define WIN32_LEAN_AND_MEAN

#include "ConsoleLogger.h"
#include <Windows.h>
#include <iostream>

HANDLE hConsole;

project::ConsoleLogger::ConsoleLogger()
{
    AllocConsole();
    int _r = freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
    if (_r != 0)
    {
        // Message d'erreur...
        LogError("erreur avec la console");
    }

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

project::ConsoleLogger::~ConsoleLogger()
{
    //If the function fails, the return value is zero.
    int _r = FreeConsole();
    if (_r == 0)
    {
        // Fail message...
        LogError("erreur avec la console");
    }
}

void project::ConsoleLogger::LogMessage(const std::string& message)
{
    SetConsoleTextAttribute(hConsole, 15);
    std::cout << message << std::endl;
}

void project::ConsoleLogger::LogError(const std::string& message)
{
    SetConsoleTextAttribute(hConsole, 12);
    std::cout << "ERROR : " << message << std::endl;
}

void project::ConsoleLogger::LogWarning(const std::string& message)
{
    SetConsoleTextAttribute(hConsole, 14);
    std::cout << "WARNING : " << message << std::endl;
}