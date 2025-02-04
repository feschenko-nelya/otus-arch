#ifndef EXCEPTIONHANDLER_H
#define EXCEPTIONHANDLER_H

#include <exception>
#include <functional>
#include <map>
#include <memory>
#include <set>
#include <unordered_map>

#include "ICommand.h"

class ExceptionHandler
{
public:
    static ExceptionHandler &inst();
    virtual ~ExceptionHandler() = default;

    ICommand *handle(std::shared_ptr<ICommand> cmd, const std::exception &exc);

protected:

    enum class ResultFunction
    {
        WriteToLogCmdToCmdQueue,
        WriteToLogCmd,
        RepeatCmdInQueue,
        OneRepeatThenLogCmd,
        RepeatTwiceThenLogCmd,
    };

    /// Данные по команде и исключению: хеш-код класса команды и исключения
    struct CmdExcData
    {
        size_t cmd;
        size_t exc;

        bool operator < (const CmdExcData &data) const
        {
            return ((cmd == data.cmd) && (exc < data.exc))
                   || (cmd < data.cmd);
        }
    };

    std::map<CmdExcData, ResultFunction> _handlers;
    std::map<ResultFunction, std::function<ICommand *(std::shared_ptr<ICommand>, const std::exception &ex)>> _funcs;
    /// Счётчик команд и исключений
    std::map<CmdExcData, int> _counter;

    ExceptionHandler();
    void checkIn(const ICommand *cmd, const std::exception &exc);

};

#endif // EXCEPTIONHANDLER_H
