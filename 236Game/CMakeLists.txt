add_library(gameLib "")

target_sources(gameLib 
                PUBLIC 
                "${CMAKE_CURRENT_LIST_DIR}/scenes.cpp")

target_link_libraries(gameLib PRIVATE GameEngine)

add_executable(Game "GameApp.cpp")

target_link_libraries(Game PRIVATE GameEngine)

target_include_directories(Game PUBLIC 
                    "${CMAKE_CURRENT_LIST_DIR}")