cmake_minimum_required(VERSION 3.27)
project(SortedSet)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SortedSet
        App.cpp
        ExtendedTest.cpp
        ShortTest.cpp
        SortedSet.cpp
        SortedSetIterator.cpp)
