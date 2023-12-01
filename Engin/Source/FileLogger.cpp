#include "FileLogger.h"

project::FileLogger::FileLogger() : FileLogger("logs.txt")
{
}

project::FileLogger::FileLogger(const std::string& filename) : m_logFile(filename)
{
}

project::FileLogger::~FileLogger()
{
    if (m_logFile.is_open())
    {
        m_logFile.close();
    }
}

void project::FileLogger::LogMessage(const std::string& message)
{
    if (m_logFile.is_open())
    {
        m_logFile << message << std::endl;
    }
}

void project::FileLogger::LogError(const std::string& message)
{
    if (m_logFile.is_open())
    {
        m_logFile << "ERROR : " << message << std::endl;
    }
}

void project::FileLogger::LogWarning(const std::string& message)
{
    if (m_logFile.is_open())
    {
        m_logFile << "WARNING : " << message << std::endl;
    }
}