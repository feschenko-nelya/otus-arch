#include "CommandQueue.h"

CommandQueue::~CommandQueue()
{
    clear();
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
        auto cmd = _cmdQueue.front();

        cmd->execute();

        --_count;

        _cmdQueue.pop();
    }
}

void CommandQueue::add(std::shared_ptr<ICommand> cmd)
{
    if (cmd)
    {
        _cmdQueue.push(cmd);

        ++_count;
    }
}

void CommandQueue::clear()
{
    while (!_cmdQueue.empty())
    {
        _cmdQueue.pop();
    }

    _count = 0;
}

int CommandQueue::count() const
{
    return _count;
}
