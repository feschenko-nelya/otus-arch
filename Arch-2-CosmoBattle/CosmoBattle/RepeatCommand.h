#ifndef REPEATCOMMAND_H
#define REPEATCOMMAND_H

#include "ICommand.h"
#include <memory>

class RepeatCommand : public ICommand
{
public:
    RepeatCommand(std::shared_ptr<ICommand> cmd);
    ~RepeatCommand() = default;

    void execute() override;

private:
    std::shared_ptr<ICommand> _cmd;

};

class RepeatTwiceCommand : public ICommand
{
public:
    RepeatTwiceCommand(std::shared_ptr<ICommand> cmd);
    ~RepeatTwiceCommand() = default;

    void execute() override;

private:
    std::shared_ptr<ICommand> _cmd;

};


#endif // REPEATCOMMAND_H
