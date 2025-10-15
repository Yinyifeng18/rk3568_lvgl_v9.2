file(GLOB_RECURSE SOURCES src/*.c)
add_library(lv_code STATIC ${SOURCES})

target_include_directories(lv_code SYSTEM PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
