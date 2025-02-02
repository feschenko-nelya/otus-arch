#include <gtest/gtest.h>

#include <fstream>
#include <memory>
#include <exception>
#include <functional>

#include "../CosmoBattle/UObject.h"
#include "../CosmoBattle/MovingObject.h"
#include "../CosmoBattle/MoveCommand.h"
#include "../CosmoBattle/RotatingObject.h"
#include "../CosmoBattle/RotateCommand.h"
#include "../CosmoBattle/RepeatCommand.h"
#include "../CosmoBattle/CommandQueue.h"
#include "../CosmoBattle/ExceptionHandler.h"
#include "../CosmoBattle/UObjectException.h"
#include "../CosmoBattle/ExceptionCommand.h"

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
    auto object = std::make_shared<UObject>();

    Vector baseLocation;
    baseLocation.setCoordinate("x", 12);
    baseLocation.setCoordinate("y", 5);

    Vector baseVelocity;
    baseVelocity.setCoordinate("x", -70);
    baseVelocity.setCoordinate("y", -30);

    object->setProperty("location", baseLocation);
    object->setProperty("velocity", baseVelocity);
    object->setProperty("angle", Angle{0});

    auto moveObj = std::make_shared<MovingObject>(object);

    auto moveCmd = std::make_shared<MoveCommand>(moveObj);

    try
    {
        moveCmd->execute();

        FAIL();
    }
    catch (std::exception &exc)
    {
        CommandQueue::inst().clear();

        const int previousCount = CommandQueue::inst().count();

        std::unique_ptr<ICommand> excCmd(ExceptionHandler::inst().handle(moveCmd, exc));
        EXPECT_TRUE(excCmd.get() == nullptr);

        EXPECT_EQ(CommandQueue::inst().count(), previousCount + 1);

        ASSERT_THROW(CommandQueue::inst().execute(), UObjectOutOfSpace);

        CommandQueue::inst().clear();
    }
}

TEST(ExceptionHandler, RepeatThenLogCmd)
{
    auto object = std::make_shared<UObject>();
    object->setProperty("angle", Angle{45});
    object->setProperty("angular_velocity", Angle{3000});

    auto rotatingObject = std::make_shared<RotatingObject>(object);

    auto rotateCmd = std::make_shared<RotateCommand>(rotatingObject);

    try
    {
        rotateCmd->execute();

        FAIL();
    }
    catch (std::exception &exc)
    {
        std::unique_ptr<ICommand> excCmd(ExceptionHandler::inst().handle(rotateCmd, exc));
        EXPECT_TRUE(excCmd.get() != nullptr);

        auto cmdi = excCmd.get();
        EXPECT_EQ(std::string(typeid(*cmdi).name()), std::string(typeid(RepeatCommand).name()));

        try
        {
            cmdi->execute();
            FAIL();
        }
        catch (std::exception &exc2)
        {
            std::unique_ptr<ICommand> excCmd(ExceptionHandler::inst().handle(rotateCmd, exc2));
            EXPECT_TRUE(excCmd.get() != nullptr);

            auto cmdi = excCmd.get();
            EXPECT_EQ(std::string(typeid(*cmdi).name()), std::string(typeid(WriteExceptionToLogCommand).name()));
        }
    }
}
