#pragma once
#include <ILogger.h>

namespace project
{
    class ConsoleLogger : public ILogger
    {
    public:
        ConsoleLogger();
        virtual ~ConsoleLogger();

        virtual void LogMessage(const std::string& message) override;
        virtual void LogError(const std::string& message) override;
        virtual void LogWarning(const std::string& message) override;
    };
}
