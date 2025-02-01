#ifndef EXCEPTIONHANDLER_H
#define EXCEPTIONHANDLER_H

#include <exception>
#include <functional>
#include <memory>
#include <set>
#include <unordered_map>

#include "ICommand.h"

class ExceptionHandler
{
public:
    static ExceptionHandler &inst();
    ~ExceptionHandler() = default;

    ICommand *handle(std::shared_ptr<ICommand> cmd, const std::exception &exc);

private:
    ExceptionHandler();

    void checkIn(const ICommand *cmd, const std::exception &exc);

    enum class ResultCommand
    {
        WriteToLogCmdToCmdQueue,
        WriteToLogCmd,
        RepeatCmdInQueue,
    };

    std::unordered_map<size_t, // command
                       std::unordered_map<size_t, // exception
                                          ResultCommand>> _handlers;

    std::unordered_map<ResultCommand, std::function<ICommand *(std::shared_ptr<ICommand>, const std::exception &ex)>> _funcs;

    struct CommandExceptionCounterData
    {
        size_t cmd;
        size_t exc;
        int count = 0;

        bool operator < (const CommandExceptionCounterData& data) const
        {
            return (cmd < data.cmd) && (exc < data.exc);
        }
    };

    std::set<CommandExceptionCounterData> _counter;
};

#endif // EXCEPTIONHANDLER_H
