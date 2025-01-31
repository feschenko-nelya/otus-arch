cmake_minimum_required(VERSION 3.14)

project(CosmoBattle LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CosmoBattle
  main.cpp
  UObject.h UObject.cpp
  UObjectException.cpp UObjectException.h
  MoveCommand.h MoveCommand.cpp
  MovingObject.h MovingObject.cpp
  ICommand.h
  DataStructs.cpp
  DataStructs.h
  RotatingObject.h RotatingObject.cpp
  RotateCommand.h RotateCommand.cpp
  Settings.h Settings.cpp
  LogCommand.h LogCommand.cpp
  ExceptionCommand.h ExceptionCommand.cpp
  CommandQueue.h CommandQueue.cpp
  ExceptionHandler.h ExceptionHandler.cpp
  RepeatCommand.h RepeatCommand.cpp
)

include(GNUInstallDirs)
install(TARGETS CosmoBattle
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
