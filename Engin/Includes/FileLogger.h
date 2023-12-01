#pragma once
#include "ILogger.h"
#include <iostream>
#include <fstream>

namespace project
{
    // Class for logging messages to a file.
    class FileLogger : public ILogger
    {
    public:
        // Default constructor.
        FileLogger();

        // Constructor that specifies a log file name.
        FileLogger(const std::string& filename);

        // Destructor.
        virtual ~FileLogger();

        // Logs a general message to the file.
        virtual void LogMessage(const std::string& message) override;

        // Logs an error message to the file.
        virtual void LogError(const std::string& message) override;

        // Logs a warning message to the file.
        virtual void LogWarning(const std::string& message) override;

    private:
        std::ofstream m_logFile; // Output file stream for logging.
    };
}
