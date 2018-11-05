cmake_minimum_required (VERSION 2.8)


set(CMAKE_BUILD_TYPE "Debug")
add_subdirectory(src)

include_directories("./include")
aux_source_directory(. DIR_SRCS)
add_executable(unicodetest ${DIR_SRCS})
target_link_libraries(unicodetest unicode)
