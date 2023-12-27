cmake_minimum_required(VERSION 3.27)
project(libmumble_server VERSION 0.0.1)

# Use libc++ instead of libstdc++ (Clang only)
if (${CMAKE_CXX_COMPILER_ID} STREQUAL Clang)
    option(USE_LIBCPP "Use libc++ as C++ standard library" OFF)
    if (USE_LIBCPP)
        add_compile_options(-stdlib=libc++)
    endif ()
endif ()

include(GNUInstallDirs)

add_subdirectory(mumble_protocol)
