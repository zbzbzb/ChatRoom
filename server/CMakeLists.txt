cmake_minimum_required(VERSION 3.10)
project(server)

set(CMAKE_CXX_STANDARD 11)

add_executable(server main.cpp Server.cpp Server.h Handler.cpp Handler.h Config.cpp Config.h Functools.cpp Functools.h test.cpp ThreadPool.cpp ThreadPool.h Exception.cpp Exception.h)