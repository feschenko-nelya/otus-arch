cmake_minimum_required(VERSION 3.14)

project(Tests LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(Tests main.cpp
    ../CosmoBattle/DataStructs.cpp ../CosmoBattle/DataStructs.h
    ../CosmoBattle/UObject.cpp ../CosmoBattle/UObject.h
    ../CosmoBattle/UObjectException.cpp ../CosmoBattle/UObjectException.h
    ../CosmoBattle/MovingObject.cpp ../CosmoBattle/MovingObject.h
    ../CosmoBattle/MoveCommand.cpp ../CosmoBattle/MoveCommand.h
    ../CosmoBattle/RotatingObject.h ../CosmoBattle/RotatingObject.cpp
    ../CosmoBattle/RotateCommand.h ../CosmoBattle/RotateCommand.cpp
    ../CosmoBattle/RepeatCommand.h ../CosmoBattle/RepeatCommand.cpp
    ../CosmoBattle/Settings.h ../CosmoBattle/Settings.cpp
    ../CosmoBattle/LogCommand.cpp ../CosmoBattle/LogCommand.h
    ../CosmoBattle/ExceptionCommand.cpp ../CosmoBattle/ExceptionCommand.h
    ../CosmoBattle/CommandQueue.cpp ../CosmoBattle/CommandQueue.h
    ../CosmoBattle/ExceptionHandler.cpp ../CosmoBattle/ExceptionHandler.h
    TestUObject.cpp
    TestMovingObject.cpp
    TestMoveCommand.cpp
    TestRotatingObject.cpp
    TestRotateCommand.cpp
    TestVector.cpp
    #TestLogCommand.cpp
    #TestExceptionCommand.cpp
    #TestCommandQueue.cpp
    #TestExceptionHandler.cpp
    #TestRepeatCommand.cpp
)

target_include_directories(
        Tests
        PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(Tests gtest_main gmock_main)

add_test(NAME UObject COMMAND Tests)
add_test(NAME Vector COMMAND Tests)
add_test(NAME MovingObject COMMAND Tests)
add_test(NAME MoveCommand COMMAND Tests)
add_test(NAME RotatingObject COMMAND Tests)
add_test(NAME RotateCommand COMMAND Tests)
add_test(NAME LogCommand COMMAND Tests)
add_test(NAME ExceptionCommand COMMAND Tests)
add_test(NAME CommandQueue COMMAND Tests)
add_test(NAME RepeatCommand COMMAND Tests)
add_test(NAME ExceptionHandler COMMAND Tests)
