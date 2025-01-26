#include <gtest/gtest.h>
#include <fstream>

#include "../CosmoBattle/UObject.h"
#include "../CosmoBattle/MovingObject.h"
#include "../CosmoBattle/MoveCommand.h"
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
}
