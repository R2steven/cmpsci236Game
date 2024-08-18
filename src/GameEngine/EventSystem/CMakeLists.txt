add_library(EventManager "")

target_sources(EventManager 
                PRIVATE
                    "${CMAKE_CURRENT_LIST_DIR}/EventManager.cpp"
                PUBLIC
                    "${CMAKE_CURRENT_LIST_DIR}/EventManager.h"
                    "${CMAKE_CURRENT_LIST_DIR}/Event.h")

target_include_directories(EventManager
                PUBLIC
                "${CMAKE_CURRENT_LIST_DIR}")