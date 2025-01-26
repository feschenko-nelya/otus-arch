#ifndef EXCEPTIONHANDLER_H
#define EXCEPTIONHANDLER_H

#include <exception>
#include <functional>
#include <unordered_map>

#include "ICommand.h"

class ExceptionHandler
{
public:
    static ExceptionHandler &inst();
    ~ExceptionHandler() = default;

    ICommand *handle(const ICommand *cmd, const std::exception &exc);

private:
    ExceptionHandler();

    enum class ResultCommand
    {
        WriteToLogCmdToCmdQueue,
        WriteToLogCmd,
    };

    std::unordered_map<size_t, // cmd
                       std::unordered_map<size_t, // exc
                                          ResultCommand>> _handlers;

    std::unordered_map<ResultCommand, std::function<ICommand *(const ICommand *, const std::exception &ex)>> _funcs;
};

#endif // EXCEPTIONHANDLER_H
