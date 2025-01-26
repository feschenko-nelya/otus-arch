#ifndef EXCEPTIONCOMMAND
#define EXCEPTIONCOMMAND

#include <exception>
#include <string>

#include "ICommand.h"

class WriteExceptionToLogCommand : public ICommand
{
public:
    WriteExceptionToLogCommand(const std::exception &ex);

    void execute() override;

private:
    std::string _excText;

};

#endif // EXCEPTIONCOMMAND
