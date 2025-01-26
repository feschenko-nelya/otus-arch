#include <gtest/gtest.h>
#include <fstream>

#include "../CosmoBattle/LogCommand.h"
#include "../CosmoBattle/Settings.h"

TEST(LogCommand, ConsoleLogExecute)
{
    std::stringbuf newCoutBuf(std::ios::out);
    std::cout.rdbuf(std::addressof(newCoutBuf));

    const std::string testLog("some log");
    ConsoleLogCommand cmd(testLog);

    ASSERT_NO_THROW(cmd.execute());

    EXPECT_EQ(newCoutBuf.str(), testLog);
}

TEST(LogCommand, FileLogExecute)
{
    const std::string testLog("some log");
    FileLogCommand cmd(testLog);

    ASSERT_NO_THROW(cmd.execute());

    std::ifstream ifs;
    ifs.open(Settings::inst().getLogFile());

    std::string log_line;
    std::getline(ifs, log_line);

    EXPECT_EQ(log_line, testLog);

    ifs.close();
}
