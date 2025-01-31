#ifndef COMMANDQUEUE_H
#define COMMANDQUEUE_H

#include <memory>
#include <queue>

#include "ICommand.h"


class CommandQueue : public ICommand
{
public:
    ~CommandQueue();

    static CommandQueue &inst();

    void add(std::shared_ptr<ICommand> cmd);
    void execute() override;
    int count() const;
    void clear();

private:
    CommandQueue() = default;

    std::queue<std::shared_ptr<ICommand>> _cmdQueue;
    int _count = 0;
};

#endif // COMMANDQUEUE_H
