#include "RepeatCommand.h"
#include "ExceptionCommand.h"

RepeatCommand::RepeatCommand(std::shared_ptr<ICommand> cmd)
{
    _cmd = cmd;
}

void RepeatCommand::execute()
{
    _cmd->execute();
}


RepeatTwiceCommand::RepeatTwiceCommand(std::shared_ptr<ICommand> cmd)
{
    _cmd = cmd;
}

void RepeatTwiceCommand::execute()
{
    const short END_STEP = 2;
    short step = 0;

    while (step <= END_STEP)
    {
        try
        {
            _cmd->execute();

            return;
        }
        catch (std::exception &ex)
        {
            if (step == END_STEP)
            {
                WriteExceptionToLogCommand cmd(ex);
                cmd.execute();

                return;
            }
            else
            {
                ++step;
            }
        }
    }
}
