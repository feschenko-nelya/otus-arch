#include <gtest/gtest.h>
#include <fstream>

#include "../CosmoBattle/UObjectException.h"
#include "../CosmoBattle/ExceptionCommand.h"
#include "../CosmoBattle/Settings.h"

TEST(ExceptionCommand, WriteToLogExecute)
{
    std::ifstream ifs;
    ifs.open(Settings::inst().getLogFile());

    // удалить лог файл, если остался с прошлого запуска теста
    if (ifs.is_open())
    {
        ifs.close();
        std::remove(Settings::inst().getLogFile().c_str());
    }

    UObjectAbsentPropertyException exc("property");

    WriteExceptionToLogCommand cmd(exc);

    std::stringbuf newCoutBuf(std::ios::out);
    std::cout.rdbuf(std::addressof(newCoutBuf));

    ASSERT_NO_THROW(cmd.execute());

    // проверить запись в консоль
    EXPECT_EQ(newCoutBuf.str(), std::string(exc.what()));

    // проверить запись в файл
    ifs.open(Settings::inst().getLogFile());
    EXPECT_EQ(ifs.is_open(), true);

    std::string log_line;
    std::getline(ifs, log_line);

    EXPECT_EQ(log_line, std::string(exc.what()));

    ifs.close();

    std::remove(Settings::inst().getLogFile().c_str());
}
