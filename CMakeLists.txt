cmake_minimum_required(VERSION 3.22 FATAL_ERROR)
project(sprx LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(spore)

target_compile_definitions(
    spore
    PUBLIC
    $<$<CONFIG:Debug>:"___SPRX_DEBUG">
)
target_compile_definitions(
    spore
    PUBLIC
    $<$<CONFIG:RelWithDebInfo>:
    "___SPRX_DEBUG"
    "___SPRX_RELWITHDEBINFO"
    >
)
target_compile_definitions(
    spore
    PUBLIC
    $<$<CONFIG:Release>:
    "___SPRX_RELEASE"
    >
)
target_compile_definitions(
    spore
    PUBLIC
    $<$<CONFIG:MinSizeRel>:
    "___SFCX_RELEASE"
    "___SFCX_MINSIZEREL"
    >
)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
        message(STATUS "Configurating for Linux")
        target_compile_definitions(
            spore
            PUBLIC
            "___SPRX_LINUX"
        )
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
        message(STATUS "Configurating for Darwin")
        target_compile_definitions(
            spore
            PUBLIC
            "___SPRX_DARWIN"
        )
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
        message(STATUS "Configurating for Windows")
        target_compile_definitions(
            spore
            PUBLIC
            "___SPRX_WINDOWS"
        )
else()
       message(SEND_ERROR "Failed to configurate for an unknown platform")
endif()

add_subdirectory(include)
add_subdirectory(library)
add_subdirectory(source)