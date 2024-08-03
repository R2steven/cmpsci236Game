add_library(GameEngine "")

target_sources(GameEngine 
                PRIVATE
                    "${CMAKE_CURRENT_LIST_DIR}/Engine.cpp"
                PUBLIC
                    "${CMAKE_CURRENT_LIST_DIR}/GameEngine.h"
                    "${CMAKE_CURRENT_LIST_DIR}/Engine.h")

add_library(EventManager "")

target_sources(EventManager 
                PRIVATE
                    "${CMAKE_CURRENT_LIST_DIR}/EventManager.cpp"
                PUBLIC
                    "${CMAKE_CURRENT_LIST_DIR}/EventManager.h")

add_library(RenderEngine  "")

target_sources(RenderEngine
                PRIVATE
                    "${CMAKE_CURRENT_LIST_DIR}/RenderEngine.cpp"
                PUBLIC
                    "${CMAKE_CURRENT_LIST_DIR}/RenderEngine.h")

target_link_libraries(GameEngine PRIVATE EventManager RenderEngine)

target_include_directories(GameEngine
                PUBLIC
                "${CMAKE_CURRENT_LIST_DIR}")