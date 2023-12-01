#pragma once
#include <string>

namespace project {

    // Interface for logging functionalities.
    class ILogger {
    public:
        // Virtual destructor.
        virtual ~ILogger() = default;

        // Logs a general message.
        virtual void LogMessage(const std::string& message) = 0;

        // Logs an error message.
        virtual void LogError(const std::string& message) = 0;

        // Logs a warning message.
        virtual void LogWarning(const std::string& message) = 0;
    };
}
