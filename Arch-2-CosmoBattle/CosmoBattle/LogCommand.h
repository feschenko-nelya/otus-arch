#ifndef LOGCOMMAND_H
#define LOGCOMMAND_H

#include "ICommand.h"

#include <memory>
#include <fstream>
#include <vector>

class LogCommandException;

class AbstractLogCommand : ICommand
{
public:
    AbstractLogCommand(const std::string &logString);
    virtual ~AbstractLogCommand() = default;

    void execute() override;

protected:
    virtual std::ostream *getOstream() = 0;

private:
    std::string _logString;
};


class ConsoleLogCommand : public AbstractLogCommand
{
public:
    ConsoleLogCommand(const std::string &logString);
    ~ConsoleLogCommand() = default;

protected:
    std::ostream *getOstream() override;

private:
    std::unique_ptr<std::ostream> _consoleStream;
};

class FileLogCommand : public AbstractLogCommand
{
public:
    FileLogCommand(const std::string &logString);
    ~FileLogCommand() = default;

protected:
    std::ostream *getOstream() override;

private:
    std::unique_ptr<std::ofstream> _fileStream;
};


class LogCommandException : public std::exception
{
public:
    LogCommandException(const std::string &text);
    ~LogCommandException() = default;

    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override;

private:
    std::string _exceptionText;
};

#endif // LOGCOMMAND_H
