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

add_executable(Tests TestUObject.cpp
    ../CosmoBattle/DataStructs.cpp ../CosmoBattle/DataStructs.h
    ../CosmoBattle/UObject.cpp ../CosmoBattle/UObject.h
    ../CosmoBattle/UObjectException.cpp ../CosmoBattle/UObjectException.h
    ../CosmoBattle/MovingObject.cpp ../CosmoBattle/MovingObject.h
    ../CosmoBattle/MoveCommand.cpp ../CosmoBattle/MoveCommand.h
    ../CosmoBattle/RotatingObject.h ../CosmoBattle/RotatingObject.cpp
    TestMovingObject.cpp
    TestMoveCommand.cpp
    TestRotatingObject.cpp
    TestRotateCommand.cpp
)

target_include_directories(
        Tests
        PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(Tests gtest_main gmock_main)

add_test(NAME UObject COMMAND Tests)
add_test(NAME MovingObject COMMAND Tests)
add_test(NAME MoveCommand COMMAND Tests)
add_test(NAME RotatingObject COMMAND Tests)
