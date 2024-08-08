cmake_minimum_required(VERSION 3.29)

project(236Game VERSION 0.1
                DESCRIPTION "A Textual RPG Project for Students to Learn OOP with C++"
                LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# The directory where we will keep our Engine code
add_subdirectory(src)

# The directory where we will keep out main game
add_subdirectory(236Game)
# The directory where we will keep our tests
include(CTest)
add_subdirectory(test)