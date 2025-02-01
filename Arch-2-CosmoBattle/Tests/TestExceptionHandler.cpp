#include <gtest/gtest.h>
#include <fstream>

#include "../CosmoBattle/UObject.h"
#include "../CosmoBattle/MovingObject.h"
#include "../CosmoBattle/MoveCommand.h"
#include "../CosmoBattle/RotatingObject.h"
#include "../CosmoBattle/RotateCommand.h"
#include "../CosmoBattle/CommandQueue.h"
#include "../CosmoBattle/ExceptionHandler.h"

TEST(ExceptionHandler, HandleWriteLog)
{
    auto object = std::make_shared<UObject>();
    object->setProperty("x", 0.9);

    auto moveObj = std::make_shared<MovingObject>(object);

    auto moveCmd = std::make_shared<MoveCommand>(moveObj);
    try
    {
        moveCmd->execute();

        FAIL();
    }
    catch (std::exception &exc)
    {
        std::unique_ptr<ICommand> excCmd(ExceptionHandler::inst().handle(moveCmd, exc));

        EXPECT_TRUE(excCmd.get() != nullptr);
    }
}

TEST(ExceptionHandler, HandleWriteLogInQueue)
{
    auto object = std::make_shared<UObject>();
    object->setProperty("x", 0.9);

    auto rotateObj = std::make_shared<RotatingObject>(object);
    auto rotateCmd = std::make_shared<RotateCommand>(rotateObj);

    try
    {
        rotateCmd->execute();
        FAIL();
    }
    catch (std::exception &exc)
    {
        CommandQueue::inst().clear();

        const int previousCount = CommandQueue::inst().count();

        std::unique_ptr<ICommand> excCmd(ExceptionHandler::inst().handle(rotateCmd, exc));
        EXPECT_TRUE(excCmd.get() == nullptr);

        EXPECT_EQ(CommandQueue::inst().count(), previousCount + 1);

        CommandQueue::inst().clear();
    }
}

TEST(ExceptionHandler, RepeatCmdInQueue)
{

}
