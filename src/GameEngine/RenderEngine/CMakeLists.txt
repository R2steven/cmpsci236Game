add_library(RenderEngine  "")

target_sources(RenderEngine
                PRIVATE
                    "${CMAKE_CURRENT_LIST_DIR}/ConsoleRenderer.cpp"
                PUBLIC
                    "${CMAKE_CURRENT_LIST_DIR}/RenderEngine.h"
                    "${CMAKE_CURRENT_LIST_DIR}/Renderable.h"
                    "${CMAKE_CURRENT_LIST_DIR}/ConsoleRenderer.h")

target_include_directories(RenderEngine
                PUBLIC
                "${CMAKE_CURRENT_LIST_DIR}"
                "${CMAKE_SOURCE_DIR}/src/GameEngine/base")
