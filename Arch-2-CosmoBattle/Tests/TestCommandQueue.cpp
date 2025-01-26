#include <gtest/gtest.h>
#include <fstream>

#include "../CosmoBattle/CommandQueue.h"
#include "../CosmoBattle/LogCommand.h"

TEST(CommandQueue, ConsoleLogExecute)
{
    CommandQueue::inst().add(nullptr);

    EXPECT_EQ(CommandQueue::inst().count(), 0);

    CommandQueue::inst().add(new ConsoleLogCommand("log text"));

    EXPECT_EQ(CommandQueue::inst().count(), 1);

    ASSERT_NO_THROW(CommandQueue::inst().execute());

    EXPECT_EQ(CommandQueue::inst().count(), 0);
}
