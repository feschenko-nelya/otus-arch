#include "RepeatCommand.h"

#include "UObjectException.h"

RepeatCommand::RepeatCommand(std::shared_ptr<ICommand> cmd)
{
    _cmd = cmd;
}

void RepeatCommand::execute()
{
    if (_cmd.expired())
    {
        throw CommandExpired();
    }

    _cmd.lock()->execute();
}
