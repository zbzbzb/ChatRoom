cmake_minimum_required(VERSION 3.10)
project(server)

set(CMAKE_CXX_STANDARD 11)

LINK_DIRECTORIES(/usr/local/lib)

LINK_LIBRARIES(glog pthread)

add_executable(server main.cpp Server.cpp Server.h Handler.cpp Handler.h Config.cpp Config.h Functools.cpp Functools.h test.cpp ThreadPool.cpp ThreadPool.h Exception.cpp Exception.h Task.cpp Task.h Epoll.cpp Epoll.h User.cpp User.h)