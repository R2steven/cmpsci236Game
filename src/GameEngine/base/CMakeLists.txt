add_library(base "")

target_sources(base
                PUBLIC
                    "${CMAKE_CURRENT_LIST_DIR}/base.h"
                )


target_include_directories(base 
                PUBLIC
                "${CMAKE_CURRENT_LIST_DIR}")


set_target_properties(base PROPERTIES LINKER_LANGUAGE CXX)