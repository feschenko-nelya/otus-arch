cmake_minimum_required(VERSION 3.14)

project(TDD LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TDD
  main.cpp
  Equation.h Equation.cpp
  EquationException.h EquationException.cpp
)

include(GNUInstallDirs)
install(TARGETS TDD
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
