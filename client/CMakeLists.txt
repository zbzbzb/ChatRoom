cmake_minimum_required(VERSION 3.10)
project(client)

set(CMAKE_CXX_STANDARD 11)

add_executable(client main.cpp ClientMes.cpp ClientMes.h Client.cpp Client.h ServerMes.cpp ServerMes.h md5.cpp md5.h Functools.cpp Functools.h)