#include "CommandQueue.h"

CommandQueue::~CommandQueue()
{
    while (!_cmdQueue.empty())
    {
        auto cmd = _cmdQueue.front();
        delete cmd;

        _cmdQueue.pop();
    }
}

CommandQueue &CommandQueue::inst()
{
    static CommandQueue cmdQueue;

    return cmdQueue;
}

void CommandQueue::execute()
{
    if (!_cmdQueue.empty())
    {
        if (auto cmd = _cmdQueue.front())
        {
            cmd->execute();

            delete cmd;
        }

        --_count;

        _cmdQueue.pop();
    }
}

void CommandQueue::add(ICommand *cmd)
{
    if (cmd)
    {
        _cmdQueue.push(cmd);

        ++_count;
    }
}

int CommandQueue::count() const
{
    return _count;
}
