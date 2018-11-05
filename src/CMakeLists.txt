cmake_minimum_required (VERSION 2.8)

include_directories("../include")
aux_source_directory(. DIR_SRCS)
add_library(unicode STATIC ${DIR_SRCS})
