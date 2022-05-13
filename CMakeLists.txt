cmake_minimum_required(VERSION 3.5)
project(DS_Udemy)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14 -save-temps")

add_executable(runApp 
                src/Main.cpp
                src/53_TailRecursion.cpp
                src/54_HeadRecursion.cpp
                src/56_TreeRecursion.cpp
                src/58_IndirectRecursion.cpp
                src/60_NestedRecursion.cpp
                src/61_SumOfN_Rec.cpp
                src/63_FactOfN_Rec.cpp
                src/65_PowerOfN_Rec.cpp)