cmake_minimum_required(VERSION 3.22)
project(C11Feature)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -O2")

add_executable(Template Template.cpp)
add_executable(InitializerList InitializerList.cpp)
add_executable(RvalueReference RvalueReference.cpp)
add_executable(SingletonTest Singleton/SingletonTest.cpp)
add_executable(Thread1 Thread.cpp)