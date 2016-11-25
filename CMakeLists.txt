cmake_minimum_required(VERSION 3.6)
project(sources_dico)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.c gestlib.h)
add_executable(sources_dico gestbib.c ${SOURCE_FILES})