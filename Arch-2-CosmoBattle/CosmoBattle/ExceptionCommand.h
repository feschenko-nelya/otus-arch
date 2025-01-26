#ifndef EXCEPTIONCOMMAND
#define EXCEPTIONCOMMAND

#include <exception>

#include "ICommand.h"

class WriteExceptionToLogCommand : public ICommand
{
public:
    WriteExceptionToLogCommand(std::exception *ex);

    void execute() override;

private:
    std::exception *_ex = nullptr;

};

#endif // EXCEPTIONCOMMAND
