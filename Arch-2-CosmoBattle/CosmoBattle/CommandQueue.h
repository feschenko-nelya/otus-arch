#ifndef COMMANDQUEUE_H
#define COMMANDQUEUE_H

#include <queue>

#include "ICommand.h"


class CommandQueue : public ICommand
{
public:
    ~CommandQueue();

    static CommandQueue &inst();

    void add(ICommand *cmd);
    void execute() override;
    int count() const;

private:
    CommandQueue() = default;

    std::queue<ICommand *> _cmdQueue;
    int _count = 0;
};

#endif // COMMANDQUEUE_H
