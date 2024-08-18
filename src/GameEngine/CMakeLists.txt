add_subdirectory(base)

add_subdirectory(RenderEngine)

add_subdirectory(EventSystem)

add_library(GameEngine "")

target_sources(GameEngine 
                PRIVATE
                    "${CMAKE_CURRENT_LIST_DIR}/Engine.cpp"
                PUBLIC
                    "${CMAKE_CURRENT_LIST_DIR}/GameEngine.h"
                    "${CMAKE_CURRENT_LIST_DIR}/Engine.h")

target_link_libraries(GameEngine PRIVATE EventManager RenderEngine)

target_include_directories(GameEngine
                PUBLIC
                "${CMAKE_CURRENT_LIST_DIR}"
                "${CMAKE_CURRENT_LIST_DIR}/EventSystem"
                "${CMAKE_CURRENT_LIST_DIR}/RenderEngine")