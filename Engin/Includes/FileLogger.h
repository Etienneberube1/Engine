#pragma once
#include "ILogger.h"
#include <iostream>
#include <fstream>

namespace project
{
    class FileLogger : public ILogger
    {
    public:
        FileLogger();
        FileLogger(const std::string& filename);
        virtual ~FileLogger();

        virtual void LogMessage(const std::string& message) override;
        virtual void LogError(const std::string& message) override;
        virtual void LogWarning(const std::string& message) override;

    private:
        std::ofstream m_LogFile;
    };
}
