#include <gtest/gtest.h>
#include <fstream>

#include "../CosmoBattle/UObject.h"
#include "../CosmoBattle/MovingObject.h"
#include "../CosmoBattle/MoveCommand.h"
#include "../CosmoBattle/RotatingObject.h"
#include "../CosmoBattle/RotateCommand.h"
#include "../CosmoBattle/CommandQueue.h"
#include "../CosmoBattle/ExceptionHandler.h"

TEST(ExceptionHandler, Handle)
{
    UObject obj;
    obj.setProperty("x", 0.9);

    MovingObject moveObj(&obj);

    auto moveCmd = std::make_unique<MoveCommand>(&moveObj);
    try
    {
        moveCmd->execute();

        FAIL();
    }
    catch (std::exception &exc)
    {
        std::unique_ptr<ICommand> excCmd(ExceptionHandler::inst().handle(moveCmd.get(), exc));

        EXPECT_TRUE(excCmd.get() != nullptr);
    }

    RotatingObject rotateObj(&obj);
    auto rotateCmd = std::make_unique<RotateCommand>(&rotateObj);

    try
    {
        rotateCmd->execute();
        FAIL();
    }
    catch (std::exception &exc)
    {
        CommandQueue::inst().clear();

        const int previuosCount = CommandQueue::inst().count();

        std::unique_ptr<ICommand> excCmd(ExceptionHandler::inst().handle(rotateCmd.get(), exc));
        EXPECT_TRUE(excCmd.get() == nullptr);

        EXPECT_EQ(CommandQueue::inst().count(), previuosCount + 1);

        CommandQueue::inst().clear();
    }
}
