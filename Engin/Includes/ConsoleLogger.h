#pragma once
#include <ILogger.h>

namespace project
{
    // Class for logging messages to the console.
    class ConsoleLogger : public ILogger
    {
    public:
        // Constructor.
        ConsoleLogger();

        // Destructor.
        virtual ~ConsoleLogger();

        // Logs a general message to the console.
        virtual void LogMessage(const std::string& message) override;

        // Logs an error message to the console.
        virtual void LogError(const std::string& message) override;

        // Logs a warning message to the console.
        virtual void LogWarning(const std::string& message) override;
    };
}