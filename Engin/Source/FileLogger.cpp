#include "FileLogger.h"

project::FileLogger::FileLogger() : FileLogger("logs.txt")
{
}

project::FileLogger::FileLogger(const std::string& filename) : m_LogFile(filename)
{
}

project::FileLogger::~FileLogger()
{
    if (m_LogFile.is_open())
    {
        m_LogFile.close();
    }
}

void project::FileLogger::LogMessage(const std::string& message)
{
    if (m_LogFile.is_open())
    {
        m_LogFile << message << std::endl;
    }
}

void project::FileLogger::LogError(const std::string& message)
{
    if (m_LogFile.is_open())
    {
        m_LogFile << "ERROR : " << message << std::endl;
    }
}

void project::FileLogger::LogWarning(const std::string& message)
{
    if (m_LogFile.is_open())
    {
        m_LogFile << "WARNING : " << message << std::endl;
    }
}