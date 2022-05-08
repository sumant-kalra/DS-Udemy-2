cmake_minimum_required(VERSION 3.5)
project(DS_Udemy)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14 -save-temps")

add_executable(runApp 
                src/Main.cpp
                src/53_TailRecursion.cpp)