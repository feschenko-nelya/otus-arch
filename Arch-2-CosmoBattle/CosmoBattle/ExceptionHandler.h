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

    std::unordered_map<size_t,
                       std::unordered_map<size_t,
                                          std::function<ICommand *(const ICommand *, const std::exception &ex)>>> _handlers;
};

#endif // EXCEPTIONHANDLER_H
