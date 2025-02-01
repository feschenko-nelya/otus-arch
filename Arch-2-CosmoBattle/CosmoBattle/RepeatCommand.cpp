#include "RepeatCommand.h"

RepeatCommand::RepeatCommand(std::shared_ptr<ICommand> cmd)
{
    _cmd = cmd;
}

void RepeatCommand::execute()
{
    _cmd->execute();
}
