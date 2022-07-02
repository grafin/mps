cmake_minimum_required(VERSION 2.8.12)

project(MyPhysicsSim C)

set(CMAKE_COLOR_MAKEFILE OFF)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
                      "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules/")

set(CMAKE_C_FLAGS_SANITIZER "-g -fsanitize=address -fsanitize=pointer-compare -fsanitize=pointer-subtract -fsanitize=leak -fsanitize=undefined -fno-omit-frame-pointer" CACHE STRING
    "Flags used by the C compiler during sanitizer build."
    FORCE)
set(CMAKE_EXE_LINKER_FLAGS_SANITIZER
    "" CACHE STRING
    "Flags used for linking binaries during sanitizer build."
    FORCE)
set(CMAKE_SHARED_LINKER_FLAGS_SANITIZER
    "" CACHE STRING
    "Flags used by the shared libraries linker during sanitizer build."
    FORCE)

mark_as_advanced(
    CMAKE_C_FLAGS_SANITIZER
    CMAKE_EXE_LINKER_FLAGS_SANITIZER
    CMAKE_SHARED_LINKER_FLAGS_SANITIZER)

set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS Debug Release RelWithDebInfo MinSizeRel Sanitizer)

set(CMAKE_BUILD_TYPE "${CMAKE_BUILD_TYPE}" CACHE STRING
    "Build type, options are: Debug Release RelWithDebInfo MinSizeRel Sanitizer."
    FORCE)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE
      "Release"
      CACHE STRING "Choose the type of build" FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
                                               "MinSizeRel" "RelWithDebInfo")
endif()

include_directories(include)
aux_source_directory(src SRC_LIST)
aux_source_directory(src/phys SRC_LIST)

add_executable(${PROJECT_NAME} ${SRC_LIST})

find_package(SDL2 REQUIRED)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 11)
set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD_REQUIRED ON)
set_property(
  TARGET ${PROJECT_NAME}
  APPEND_STRING
  PROPERTY COMPILE_FLAGS "-Wall -Wextra -Wformat-security -pedantic -std=c11 ")
set_property(
  TARGET ${PROJECT_NAME}
  APPEND_STRING
  PROPERTY LINK_FLAGS_RELEASE "-s")
